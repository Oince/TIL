# IPv6



```c
//IPv6 전용 구조체
struct sockaddr_in6 {
    u_int16_t sin6_family; //AF_INET6
    u_int16_t sin6_port; //port 번호
    u_int32_t sin6_flowinfo;
    struct in6_addr sin6_addr; //IPv6 주소
    u_int32_t sin6_scope_id;
};

struct in6_addr {
    unsigned char s6_addr[16];
}
```

IPv6을 지원하기 위한 함수, IPv4도 지원함
```c
#include <arpa/inet.h>

//src를 숫자로 변환하여 dst에 저장
//af = IP버전, src = dotted 주소, dst = 결과를 저장하는 포인터
int inet_pton(int af, const char *src, void *dst);

//src를 문자열로 변환하여 dst에 저장
//af = IP버전, src = 네트워크 주소 구조체, dst = 결과값 저장 포인터, size = 크기
const char* inet_ntop(int af, const void *src, char *dst, socklen_t size);
```

IPv6를 위한 함수, IPv4도 지원
```c
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int getaddrinfo(const char *node, cnost char *service, const struct addrinfo *hint, struct addrinfo **res);
//node : 도메인 네임 or IP주소
//service : Application 계층 프로토콜 or Port 번호
//hint : addrinfo 구조체
//res : 결과값 저장

void freeaddrinfo(struct addrinfo *res);
//메모리 할당 해제

struct addrinfo {
    int ai_flags;
    int ai_family; //AF 값
    int ai_socktype; //소켓 타입(TCP / UDP)
    int ai_protocol; //Application 계층에서 사용하는 프로토콜, 
                     //0일 경우 모든 프로토콜을 허용
    size_t ai_addrlen; // 소켓의 길이
    struct sockaddr *ai_addr; // 소켓의 주소
    char *ai_canonname; //별명

    struct addrinfo *ai_next; // 다음 주소를 연결 리스트로 저장
}
```
