# 멀티 프로세스(Multi process)
## 단일 프로세스 서버의 한계
단일 프로세스 서버는 데이터를 순차적으로 받기 때문에 여러 클라이언트가 접속했을 경우 먼저 접속한 클라이언트의 연결이 종료되어야 그 다음 접속한 클라이언트가 보낸 데이터를 받는다.  
이 때 첫번째 클라이언트와 접속해 있는 동안 두번째 클라이언트가 데이터를 보내면 첫번째 클라이언트의 연결이 종료될 때 두번째 클라이언트가 보낸 데이터를 한번에 받게 되는 문제가 있다.  
이를 해결하는 방법으로는 
1. Multi process
2. Multi thread
3. Multipelxing  

3가지가 있다.  
첫번째로 muitl process에 대해서 다룬다.  
## 멀티 프로세스
fork 함수를 통해 부모 프로세스에서 자식 프로세스를 생성할 수 있음. 

### fork()
```c
#include <unistd.h>

pid_t fork()
```
성공시 프로세스의 pid값(자식 프로세스을 경우 0), 실패시 -1을 리턴  
fork 함수 호출시에 부모 프로세스의 정보가 자식 프로세스로 복사됨.  
공유되는 것이 아닌 복사되는 것이기 때문에 부모와 자식간의 공유하는 데이터가 없음.  
이후 각각의 프로세스가 독립적으로 실행됨.  

### wait()

```c
#include <sys/wait.h>

pid_t wait(int *status);
```
자식 프로세스의 pid를 리턴, 에러시 -1 리턴  
wait()를 호출하면 자식 프로세스중 하나가 종료될 때 까지 대기함.  
자식 프로세스가 종료되면 wait() 함수를 통해 자식 프로세스의 정보가 부모 프로세스로 전달됨.  
자식 프로세스의 상태를 status에 저장.  
```c
WIFEXITED(status) // 자식 프로세스가 정상 종료한 경우 true 리턴
WEXITSATUS(status) // 자식 프로세스의 반환 값
WIFSIGNALED(status) // 자식 프로세스가 시그널에 의해 종료되었을 경우 true 반환
```

## IPC 
프로세스 간 통신(inter process communications)  
서로 다른 프로세스들 간의 데이터를 주고 받는 것을 뜻함.  
방법을 여러가지가 있지만 여기서는 signal을 이용한 방식을 사용.  

### signal
시그널은 유닉스 계열, POSIX 호환 운영체제에서 사용되는 제한된 형태의 IPC이다.  
프로세스가 시그널 핸들러를 등록하면 그 시그널이 발생했을 때 운영체제가 핸들러를 호출한다.  
그러면 프로세스에서 핸들러 루틴을 실행하고 일반 루틴으로 돌아온다.  

#### signal()
```c
#include <signal.h>

void (*signal(int sig, void (*func)(int)))(int);
```
|||
|-|-|
|sig|signal의 종류는 지칭하는 시그널 번호|
|func|시그널이 발생했을 때 호출되는 함수|  

시그널 핸들러를 등록하는 함수.  
등록된 시그널이 발생하면 시그널 핸들러를 호출함.  

#### sigaction()
```c 
#include <signal.h>
int sigaction(int sig, const struct sigaction *restrict act, struct sigaction *restrict oldact);

struct sigaction {
    void (*sa_handler)(int);
    void (*sa_sigaction)(int, siginfo_t *, void *);
    int sa_flags;            
    sigset_t sa_mask;            
}
```
|||
|-|-|
|sig|시그널 번호|
|act|시그널 발생 시 호출되는 시그널 핸들러|
|oldact|기존에 등록되었던 시그널 핸들러|  

sigaction 구조체를 사용하여 signal 함수 보다 더 확장된 기능을 제공함.  
sa_handler에 시그널 핸들러를 등록하여 사용  
사용자가 등록하는 시그널 핸들러 외에 사전 정의된 핸들러도 있음  
|시그널 핸들러|동작|
|-|-|
|SIG_IGN|해당 시그널 무시|
|SIG_DFL|해당 시그널의 기본 동작|  

#### kill()
```c
#include <signal.h>

int kill(pid_t pid, int sig);
```
pid 프로세스에 시그널을 전달하는 함수  


### 좀비 프로세스
fork 이후 자식 프로세스를 생성하고 wait() 함수를 호출하지 않으면 자식 프로세스가 좀비 프로세스로 남아 있음.  
자식 프로세스가 종료되어도 프로세스의 정보와 반환값이 운영체제에서 유지된다.  
부모 프로세스에서 wait() 함수를 호출했을 때 자식 프로세스의 반환값을 부모 프로세스로 전달하면서 정보를 제거한다.  
하지만 wait() 함수를 호출하지 않으면 자식 프로세스가 종료되어도 정보가 남아있기 때문에 자식 프로세스는 좀비 프로세스가 되어 남아있게 된다.  
적절히 wait() 함수를 호출하여 좀비 프로세스를 없애야 한다.  

## 예제 코드
```c
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void errProc();
void errPrint();
void sigchld_handler(int sig);

int *status;

int main(int argc, char **argv) {
	int srvSd, clntSd;
	struct sockaddr_in srvAddr, clntAddr;
	int clntAddrLen, readLen, strLen;
	char rBuff[BUFSIZ];
	pid_t pid;
	
	signal(SIGCHLD, sigchld_handler);

	if(argc != 2) {
		printf("UsageL %s [port] \n", argv[0]);
		exit(1);
	}
	printf("Server start...\n");

	srvSd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(srvSd == -1) errProc();

	memset(&srvAddr, 0, sizeof(srvAddr));
	srvAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	srvAddr.sin_family = AF_INET;
	srvAddr.sin_port = htons(atoi(argv[1]));

	if(bind(srvSd, (struct sockaddr *)&srvAddr, sizeof(srvAddr)) == -1)
		errProc();
	if(listen(srvSd, 5) < 0) 
		errProc();
	clntAddrLen = sizeof(clntAddr);

	while(1) {
		clntSd = accept(srvSd, (struct sockaddr *)&clntAddr, &clntAddrLen);
		if(clntSd == -1) {
			errPrint();
			continue;
		}

		printf("client %s:%d is connected...\n", 
				inet_ntoa(clntAddr.sin_addr), 
				ntohs(clntAddr.sin_port));
		pid = fork();
		
		if(pid == 0) {
			close(srvSd);
			while(1) {
				readLen = recv(clntSd, rBuff, sizeof(rBuff) - 1, 0);
				if(readLen == 0) break;
				rBuff[readLen] = '\0';
				printf("Client(%d): %s\n", ntohs(clntAddr.sin_port), rBuff);
				send(clntSd, rBuff, strlen(rBuff), 0);
			}
			printf("Client(%d): is disconnected\n", ntohs(clntAddr.sin_port));
			close(clntSd);
			return 0;
		}
		else if(pid == -1) errProc("fork");
		else {
			close(clntSd);
		}
	}
	close(srvSd);
	return 0;
}

void errProc(const char *str) {
	fprintf(stderr, "%s: %s \n", str, strerror(errno));
	exit(1);
}

void errPrint(const char *str) {
	fprintf(stderr, "%s: %s \n", str, strerror(errno));
}

void sigchld_handler(int sig) {
	if(sig == SIGCHLD) {
		wait(status);
	}
}



```


