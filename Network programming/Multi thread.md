# Multi thread
## 멀티 프로세스와의 차이
멀티 프로세스는 fork 시점의 모든 메모리를 복사함.  
-> 메모리가 낭비되고 컨텍스트 스위칭시 오버헤드 발생  
멀티 스레드는 stack 영역을 제외한 나머지 영역을 공유 영역으로 함.   
멀티 스레드에 비해 메모리를 더 효율적으로 사용 가능하지만 공유 영역에 대한 관리가 필요함.  

## thread 관련 함수
### pthread_create()

```c
#include <pthread.h>

int pthread_create(pthread_t *thread, pthread_attr_t *attr, void *(start_routine)(void *), void *arg);
```
스레드를 생성하는 함수, 성공시 0 리턴.  
|parameter|의미|
|-|-|
|thread|스레드 id|
|attr|thread의 속성값을 저장하는 구조체(NUL 가능)|
|start_routine|스레드와 함계 호출되는 함수의 포인터|
|arg|start_routine에 전해지는 매개변수(없으면 null)|

### pthread_join()
```c
#include <pthread.h>

int pthread_join(pthread_t thread, void **retval);
```
스레드가 실행중일 때, 메인 스레드가 스레드 종료시 까지 멈추게 하는 함수  
성공시 0, 실패시 에러 번호 리턴.  
|parameter||
|-|-|
|thread|스레드 id|
|retval|스레드 반환값 포인터|

### pthread_detach()
```c
#include <pthread.h>

int pthread_detach(pthread_t thread);
```
인자로 넘어간 스레드가 종료되는 시점에 자동으로 OS에게 자원을 반환하도록 설정하는 함수.  
성공시 0, 실패시 오류코드 리턴  

## 세마포어
세마포어는 공유 자원을 관리하기 위한 기술중 하나.  
A스레드의 작업 결과가 공유 자원에 반영되지 않았을 때 B스레드가 공유 자원에 접근하여 생기는 문제를 해결하기 위한 기술.  
공유 자원에 대한 프로세스/스레드의 접근을 제한하는 방법.  
세마포어의 값이 0 이상이면 접근 가능하고, 0 이면 접근을 차단함.  
리눅스에서는 세마포어도 하나의 파일로 다룸  

### sem_open()
```c
#include <fcntl.h>
#include <semaphore.h>

sem_t *sem_open(const char *name, int oflag, mode_t mode, unsigned int 
value);
```
세마포어를 만드는 함수.  
성공시 세마포어 포인터 리턴, 실패시 SEM_FAILED 리턴

|parameter||
|-|-|
|name|세마포어 이름|
|oflag|세마포어의 특성 정의|
|mode|권한 정보 설정값 <br> 파일 접근 권한과 유사함|
|value|세마포어 초기값|

|oflag||
|-|-|
|O_RDWR|읽기, 쓰기가 가능한 형태|
|O_RDINLY|읽기만 가능|
|O_CREAT|해당 이름의 객체가 없을 경우 새로운 객체를 생성|
|O_EXCL|해당 이름의 객체가 존재하면 에러 발생|

### sem_wait()
```c
#include <semaphore.h>

int sem_wait(sem_t *sem);
```
세마포어 값을 확인하고 그 값이 양수일 경우 임계 영역에 접근하고, 0일 경우 값이 양수가 될 때 까지 임계 영역에 대한 접근을 대기 상태로 전환함.  
sem은 세마포어를 가리키는 포인터  
성공시 0, 실패시 -1 리턴

### sem_post()
```c
#include <semaphore.h>

int sem_post(sem_t *sem);
```
임계 영역을 접근한 뒤 세마포어 값을 증가시켜 다른 프로세스/스레드가 해당 영역에 접근할 수 있도록 하는 함수.  
성공시 0, 실패시 -1 리턴

### sem_unlink()
```c
#include <semaphore.h>

int sem_unlink(const char *name);
```
세마포어를 제거하는 함수.

## 뮤텍스
뮤텍스틑 세마포어와 비슷하게 임계 영역에 대한 접근을 제한하는 방법이다.  
세마포어는 여러개의 프로세스/스레드가 임계 영역에 접근할 수 있지만 뮤텍스는 한번에 하나의 프로세스/스레드만 접근할 수 있다.  

### pthread_mutex_init()
```c
#include <pthread.h>

int pthread_mutex_init(pthread_mutex_t *restrict mutex,
                       const pthread_mutexattr_t *restrictattr);
```
뮤텍스 객체를 생성하는 함수.  
성공시 0, 실패시 -1 리턴.  
|parameter||
|-|-|
|mutex|뮤텍스 객체|
|restirctattr|뮤텍스 속성 객체의 주소(NULL 가능)|

### pthread_mutex_lock() & pthread_mutex_unlock()
```c
#include <pthread.h>

int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);
```
뮤텍스 객체를 사용하여 임계 영역에 접근할 때 lock()함수를 사용하고, 접근이 끝났으면 unlock()함수를 사용한다.  
성공시 0, 실패시 에러코드를 리턴.  

### pthread_mutex_destroy()
```c
#include <pthread.h>

int pthread_mutex_destory(pthread_mutex_t *mutex);
```
뮤텍스 객체를 제거하는 함수.  
성공시 0, 실패시 에러코드 반환  
