# 싱글톤

## 개요

- 프로그램에서 오직 하나만 존재해야 하는 객제에 대한 요구사항을 해결하는 패턴
- 단 하나의 유일한 객체를 만들기 위한 패턴
- 하나의 인스턴스만 존재하도록 제한하고, 이 하나의 인스턴스를 어플리케이션 전체가 공유해야 할 때  사용
- 설정 파일, DB 커넥션 풀, 로깅 등에 사용
- 장점
  - 요청이 있을 때마다 새로운 객체를 생성하지 않고, 기존의 인스턴스를 가져와 사용하기 때문에 메모리 절감 효과가 있음
    
  - 속도 향상
  
- 단점
  - 한 객체에 너무 많은 요청이 들어올 경우 오히려 속도가 떨어질 수 있음
  - 한 객체를 공유한다는 점에서 캡슐화와 모듈성을 저해함
  - SOLID 원칙에 위배되는 경우가 많음
    - 싱글톤 인스턴스가 여러 책임을 지니게 될 경우 SRP 위반
    - 싱글톤 인스턴스가 많은 데이터를 공유하면 결합도가 높아져 OCP 위반
    - 클라이언트가 인터페이스가 아닌 구체 클래스에 의존하게 되어 DIP 위반



## 종류

### Eager Singleton

- 미리 싱글톤 객체를 생성해서 저장해두는 방법
- 간단하고 멀티 스레드 환경에서도 안전함
- 사용하지 않는 경우에도 무조건 생성하기 때문에 메모리 낭비가 있을 수 있음

```java
public class EagerSingleton {
    //미리 필드에 인스턴스를 생성해 둠
    private static final EagerSingleton instance  = new EagerSingleton();
    
	// private 생성자
    private EagerSingleton() {}

    //미리 생성해둔 인스턴스를 반환
    public static EagerSingleton getInstance() {
        return instance;
    }
}
```

### Lazy Singleton

- 객체 생성을 내부적으로 처리함
- Eager 방식의 사용하지 않는 경우는 생성하지 않는다는 단점 해결
- **Thread-safe 하지 않음**
  - A 쓰레드가 getInstance()의 if문을 실행한 후 초기화하기 전에 B 쓰레드가 실행된다면, B 쓰레드도 if문 내부로 들어갈 수 있기 때문에 2개의 인스턴스가 만들어질 수 있음


```java
class LazySingleton {
    private static LazySingleton instance;

    // private 생성자
    private LazySingleton() {}
	
    //getInstance() 호출 시 instance를 초기화하여 반환
    public static LazySingleton getInstance() {
        if (instance == null) {
            instance = new LazySingleton(); 
        }
        return instance;
    }
}
```

### Thread-safe Singleton

- synchronized를 사용해서 쓰레드가 getInstance에 하나씩 접근하도록 강제함
- 객체를 가져올 때마다 동기화를 해야하기 때문에 성능 하락이 있음

```java
class Singleton {
    private static Singleton instance;

    private Singleton() {}

    // synchronized를 사용해서 getInstance()에 lock를 검
    public static synchronized Singleton getInstance() {
        if (instance == null) {
            instance = new Singleton();
        }
        return instance;
    }
}
```

