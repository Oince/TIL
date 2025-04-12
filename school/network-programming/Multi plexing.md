# Multiplexing
## Multiplexing 이란?
하나의 프로세스로 여러 개의 클라이언트와 통신하는 방법
select, epoll 함수 사용

## selcet
관심이 있는 파일 디스크립터를 fd_set에 설정하고 등록된 이벤트(읽기/쓰기/예외)가 발생할 때 까지 기다린다.
설정된 파일 디스크립터에 대해 이벤트가 발생하면 그 파일 디스크립터를 선택하여 이후 작업을 수행한다.  
select 함수는 최대 fd값을 인자로 받아 최대 fd값까지 순회하면서 이벤트를 탐지한다.  

```c
#include <sys/select.h>

int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
```
|parameter||
|-|-|
|nfds|파일 디스크립터 중에 가장 높은 값 <br> 0 ~ nfds-1 까지 탐색함|
|readfds|읽기를 모니터링 할 fd_set|
|wirtefds|쓰기를 모니터링 할 fd_set|
|exceptfds|예외를 모니터링 할 fd_set|
|timeout|블로킹 상태를 유지할 시간 <br> NULL이면 무한대|
|return|성공시 변화가 발생한 fd의 값<br> 실패시 -1|

fd_set 설정을 위한 매크로
```c
void FD_ZERO(fd_set *fdset); // 모든 비트를 0으로 설정
void FD_SET(int fd, fd_set *fdset); // fd에 해당하는 비트를 1로 설정
void FD_CLR(int fd, fd_set *fdset); //fd에 해당하는 비트를 0으로 설정
void FD_ISSET(int fd, fd_set *fdset); //fd에 해당하는 비트가 1이면 양수 반환
```

timeval 구조체
```c
struct timeval {
    long tv_sec; //초
    long tv_usec; //마이크로초
}
```
### 동작 방식
등록된 fd_set에 대해 nfds - 1 까지 순회하면서 이벤트를 탐지한다.  
이벤트가 발생한 fd값을 리턴하고 이후 작업을 수행한다.  

select 함수는 이벤트가 발생했을 때 input으로 들어온 fd_set을 변경한다.  
이벤트가 발생한 파일 디스크립터를 제외한 나머지를 전부 0 으로 바꾼다.  
input fd_set을 수정하기 때문에 default fd_set을 유지하고, 임시 fd_set으로 복사해서 사용해야 한다.  

## epoll
select() 함수와 같은 기능을 하지만 select()와는 다르게 자신이 지정한 fd만 관찰함.  

### epoll 객체 생성
```c
#include <sys/epoll.h>

int epoll_create1(int flags);
```
성공시 epoll 객체 파일 디스크립터 반환, 실패시 -1 반환  



### epoll 객체 제어
```c
#include <sys/epoll.h>

int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
```

|parameter||
|-|-|
|epfd|epoll 파일 디스크립터 번호|
|op|하려는 작업|
||EPOLL_CTL_ADD - epoll에 파일 디스크립터 등록|
||EPOLL_CTL_MOD - epoll에 등록된 파일 디스크립터 변경|
||EPOLL_CTL_DEL - 등록된 파일 디스크립터 제거|
|fd|op와 연관된 파일 디스크립터|
|event|등록할 이벤트|

관련 구조체
```c
struct epoll_event {
    uint32_t events; //epoll 이벤트
    epoll_data_t data; //관찰하는 fd값
}
events 매크로
EPOLLIN - 읽기
EPOLLRDHUP - 소켓 연결 종료
EPOLLOUT - 쓰기
EPOLLET - 엣지 트리거 동작 지정
등등...

typedef union epoll_data {
    void *ptr;
    int fd; // 주로 fd를 사용
    uint32_t u32;
    uint64_t u64;
}epoll_data_t;
```

### wait()
```c
#include <sys/epoll.h>

int epoll_wait(int epfd, struct epoll_event *event, int maxevents, int timeout);
```

|paremeter||
|-|-|
|epfd|epoll 파일 디스크립터|
|event|이벤트 발생시 관련 정보를 저장|
|maxevents|최대 이벤트 개수|
|timeout||
