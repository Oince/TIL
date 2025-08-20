# Spring IOC, DI

## IOC

프레임워크는 원하는 기능 구현에 집중하여 개발할 수 있도록 일정한 형태와 기능을 갖추고 있는, 뼈대와 같은 역할을 한다. 프로그램 개발 시 필수적인 코드나 DB 연동과 같은 기능을 위해서 어느정도 뼈대를 제공하고, 사용자는 프레임워크가 제공해주는 구조대로 코드를 작성한다.

라이브러리는 특정 기능을 하는 코드를 모아놓은 것으로 프로그램을 개발할 때 사용 가능한 도구로서의 역할을 한다. 

라이브러리는 프레임워크와 유사한 기능을 하지만 핵심적인 차이는 **흐름을 누가 제어하느냐**이다. 라이브러리는 사용하는 사람이 직접 전체적인 흐름을 제어해야 한다. 개발 시에 필요한 기능이 있으면 가져다가 사용하는 방식이다. 반면 프레임워크는 전체적인 흐름을 프레임워크가 제어한다. 애플리케이션 코드는 프레임워크에 의해 실행된다. 애플리케이션 코드는 프레임워크의 구조 위에서 수동적으로 동작하며 사용자는 그 틀 안에서 필요한 코드를 작성한다.

이렇게 프로그램의 흐름을 사용자가 직접 제어하는 것이 아닌 외부에서 관리하는 것을 **IOC(Inversion of Controll)**라고 한다. 스프링의 IOC 컨테이너는 객체의 생성, 소멸 등의 생명 주기를 대신 관리해준다. 그리고 적절한 객체를 주입해준다. 객체의 제어권이 개발자에서 스프링 프레임워크로 넘어간 것이다. 

IOC의 장점은 다음과 같다

- 결합도 감소
  - 특정 구현에 종속되지 않고 어떤 객체가 필요한지만 알고 있으면 된다. 스프링이 외부에서 적절한 객체을 주입해 준다.
- 테스트 용이성
  - 의존성을 외부에서 주입할 수 있기 때문에 mock 객체를 쉽게 넣을 수 있다.
- 객체 재사용성 증가
  - 특정 구현에 종속되지 않기 때문에 잘 만들어진 모듈은 재사용이 가능하다.
- 유연성과 확장성
  - 결합도가 낮아졌기 때문에 기존 기능에 영향을 주지 않고 새 기능을 쉽게 추가하거나 변경할 수 있다.

## DI

**DI(Dependency Injection)**는 IOC를 구현하는 방법 중 하나이다. 객체가 의존하고 있는 다른 객체를 내부에서 직접 만들어서 사용하지 않고 스프링 컨테이너가 외부에서 주입해주는 방식이다. 스프링에서는 **@Autowired** 어노테이션으로 의존성을 주입받을 수 있다.

의존관계 자동 주입 방법에는 크게 3가지가 있다. 

### 1. 생성자 주입

```java
@Autowired
public OrderServiceImpl(MemberRepository memberRepository) {
    this.memberRepository = memberRepository;
}
```

생성자를 통해 주입받는 방식이다. 생성자 호출 시점(객체가 생생되는 시점)에 단 한번만 호출되고, final 키워드를 붙일 수 있어서 불변이는 특징이 있다. 불변이라는 특징 때문에 주로 사용되는 방식이다.  

### 2. 필드 주입

```java
@Autowired
private MemberRepository memberRepository;
```

필드에 바로 주입받는 방식이다. 코드가 간결해지는 장점이 있지만 외부에서 변경이 불가능해서 테스트가 힘들다는 단점이 있어 사용되지 않는다. 테스트 코드에서만 사용한다.  

### 3. setter 주입

```java
@Autowired
public void setMemberRepository(MemberRepository memberRepository) {
    this.memberRepository = memberRepository;
}
```

setter를 통해 주입받는 방식이다. 대부분의 경우 의존관계는 한번 설정되면 바뀌지 않아야 한다. 하지만 setter를 사용하는 방식은 메서드가 public으로 열려있어 다른 곳에서 수정할 수 있기 때문에 권장되지 않는 방식이다. 선택적인 의존 관계 주입이나, 변경이 필요할 때 제한적으로 사용한다.  

### 옵션 처리
@Autowired의 required 옵션의 기본값이 true이어서, 자동 주입 대상이 없으면 오류가 난다.  

하지만 주입 대상이 없어도 동작해야할 때 3가지 방법을 이용한다.  

1. @Autowired(required = false):  자동 주입 대상이 없으면 호출되지 않음
```java
//호출 되지 않음
@Autowired(required = false)
public void setNoBean1(Member member) {
    System.out.println("setNoBean1 = " + member);
}
```
2. @Nullable:  자동 주입 대상이 없으면 Null을 입력
```java
//null 출력
@Autowired
public void setNoBean2(@Nullable Member member) {
    System.out.println("setNoBean2 = " + member);
}
```
3. Optional<>:  자동 주입 대상이 없으면 Optional.empty 입력
```java
//Optional.empty 출력
@Autowired(required = false)
public void setNoBean3(Optional<Member> member) {
    System.out.println("setNoBean3 = " + member);
}
```
