# Concurrency
병행처리  

종류
- physical concurrency
  - cpu가 여러 개 있는 경우
- logical concurrency
  - cpu는 하나지만 논리적으로 여러 프로그램을 실행하는 경우

사용 이유: 실행 속도를 향상시키기 위함.  

**concurrency** 의 단위  
- **task**: 프로그램의 단위, **process** 라고도 함  
- **thread**: 함수 단위의 process, **LWP(경량 프로세스)** 라고도 함.  

LWP의 특징
- 자원을 적게 소모함
- 생성 시간이 짧음
- LWP끼리 통신이 쉬움

**synchronization(동기화)** 는 프로세스가 시작된 순서대로 처리하는 것 

동기화의 종류  
- competition 
  - 하나의 자원에 동시에 접근하는 경우
- cooperation
  1. 하나의 작업을 여러 프로세스가 나누어서 진행할 경우(parallel execution)
  2. 한 프로세스의 결과가 다른 프로세스의 입력으로 사용되는 경우(pipeline)

**producer-consumer problem**은 생산자 프로세스가 결과를 저장하기 전에 소비자 프로세스가 값을 읽는 문제  
이를 cooperation 동기화로 해결

**race condition** 은 두개 이상의 프로세스가 하나의 자원에 순서 없이 경쟁적으로 접근하는 상태를 뜻함.  
이를 해결하기 위해 competition 동기화를 사용함.  

competition 동기화는 mutual exclusion(상호 배제)를 사용함.  
상호 배제는 race condition이 발생한 자원에 대해 하나의 프로세스가 접근할 때 lock을 걸고, 사용이 끝나면 unlock을 하는 형식으로 사용.  

## Java thread
Java는 thread를 생성할 때 두 가지의 방법이 있다.  
- Thread 클래스 상속
- runnable 인터페이스 구현

*Thread*클래스는 runnable 인터페이스를 구현한 클래스이다.  
Thread 클래스를 사용할 때는 클래스를 상속받아 **run**메소드를 오버라이딩 한다.  
run 메소드는 스레드의 메인 함수와 같은 역할을 한다.  
run 메소드에 thread에서 수행할 작업을 작성하고, **start** 메소드를 통해 thread를 실행하면 오버라이딩된 run()메소드가 실행된다 

```java
class myThread extends Thread {
  public void run() {
    .....
  }
}
Thread myTh = new mythread();
myTh.start();
```

현재 스레드를 멈추는 **sleep** 메소드가 존재한다.  
thread를 호출한 쪽에서 그 thread가 종료할 때 까지 기다리는 **join** 메소드가 있다.  
join 메소드의 인자로 대기할 시간을 지정할 수 있다.  
```java
public void run() {
  Thread myTh = new mythread();
  myTh.start();
  //이 thread에서 진행할 작업
  myTh.join(); // myTh thread가 끝날 때 까지 기다림
  //이후 남은 작업 수행
}
```

runnable 인터페이스를 사용할 경우 해당 인터페이스를 구현한 클래스를 만들고, 그 객체를 Thread 클래스의 생성자에 넣어 Thread 객체를 생성한 후 같은 방법으로 사용할 수 있다.

thread는 일반적으로 run 메소드가 종료하면 같이 종료된다.  

### competition synchronization
자바에서는 **synchronized** 제어자를 제공한다.  
synchronized 는 메소드 앞에 붙어 메소드가 실행중일 때 그 메소드가 속해 있는 객체에 lock을 걸어 다른 thread의 접근을 막는다.  

### cooperation synchronization
Object 클래스에 정의되어 있는 wait, notify, notifyAll 메소드를 이용하여 cooperation 동기화를 제공한다.  
**wait()** 메소드는 현재 thread를 대기 상태로 전환하는 메소드이다.  
**notify()** 메소드는 대기 상태인 thread를 무작위로 하나 깨우는 메소드이다.  
**notifyAll()** 메소드는 대기 상태인 thread를 전부 깨우는 메소드이다.  
위의 메소드는 synchronized 메소드에만 사용 가능하다.  









