# Exception Handling and Event Handling

## Exception handling

**Exception**은 하드웨어나 소프트웨어어 의해 감지되고 특별한 처리가 필요한 일반적이지 않은 상황을 뜻한다  
예외가 발생했을 때 필요한 특별한 처리를 **Exception handling**이라고 한다.  
Exception handling은 **Exception handler**에 의해 처리된다.  
예외 발생을 **raised**라고 하고 C계열의 언어에서는 **throw**라는 용어를 사용한다. 

예외에는 2가지 종류가 있다.  

- predefined exception
  - OS에서 정의한 예외
  - 묵시적으로 던져짐
- user-defined exception
  - 사용자가 정의한 예외
  - 명시적으로 던져야 함

<img src="예외 처리 흐름도.png">

하나의 블록 안에서 예외가 발생할 경우 예외를 Exception handler에게 넘긴다.  
이 때 발생한 예외의 타입을 같이 넘기면, 타입에 맞는 Exception handler가 예외를 처리한다.  
만약 맞는 타입의 Exception handler가 없으면 예외는 처리되지 않고 프로그램이 종료된다.  
예외가 처리되었다면 프로그램이 다시 시작되는 위치는 다음과 같다

1. 예외 발생 문장
2. 그 다음 문장
   - unix/linux 에서 사용
3. 블록의 끝
   - jvm에서 사용

예외가 현재 실행되고 있는 함수에서 처리되지 않고 그 함수를 호출한 함수로 전파되는 것을 **propagate**라고 한다.  
예외 처리 구문이 있는 곳에서 예외가 처리되며 main함수까지 예외 처리 구문이 없다면 프로그램이 종료된다.

### Java 예시

자바에서 미리 정의된 예외 클래스는 **Exception** 클래스와 **Error** 클래스가 있다.  
Error 클래스는 JVM에서 발생시키는 에러로 사용자가 던지고 처리하는 것이 불가능하다.  
Exception 클래스는 모든 예외의 조상 클래스이며, 하위에 RuntimeException을 포함한 다양한 클래스가 있다. 

자바에는 **checked** 예외와 **unchecked** 예외가 존재한다.  
checked 예외는 컴파일러가 체크하는 예외로  catch 문이나 throws로 처리해주어야 하는 예외를 말한다.  
checked 예외에는 RuntimeException을 제외한 모든 예외가 속한다.  
uncheced 예외는 컴파일러가 체크하지 않는 예외로 예외 처리를 하지 않아도 컴파일 오류가 발생하지 않는다.  
unchecked 예외에는 RuntimeException과 Error이 속한다.

자바에서 예외처리는 **try-catch** 문을 사용한다.  
try 블럭 안에 예외가 발생 할 가능성이 있는 문장이 들어가고, 예외가 발생하면 catch에서 예외를 처리한다.  
**finally** 문은 예외 발생 여부에 관계 없이 항상 실행되어야 하는 문장을 넣는다   

```java
try {
    System.out.println(100 / 0);
} catch(ArithmeticException e) {
    System.out.println("0");
} //finally 문장 올 수 있음
```

위의 예제는 0으로 나누었을 때 발생하는 ArithmeticException처리하는 예제이다. 

**throw**키워드를 사용하면 사용자가 명시적으로 예외를 발생시킬 수 있다.

```java
try {
    throw new Exception("예외 발생");
} catch (Exception e) {
    System.out.println(e.getMessage());
}
```

**throws** 키워드는 발생한 예외를 이 메소드를 호출한 메소드로 propagate 하는 키워드이다.  
throws에는 RuntimeException을 제외한 나머지 예외를 선언해야 한다.

```java
void method() throws Exception1, ...
```

Exception 클래스를 상속받아 사용자 정의 예제를 만들 수 있다

```java
class MyException extends Exception
```

## Event Handling

Event handling은 Exception Handling과 비슷하다.  
이벤트(예외) 발생시 해당 핸들러가 호출된다는 점은 같지만 차이점으로는 예외가 사용자나 하드웨어/소프트웨어에 의해 던져지는 반면에 이벤트는 GUI를 통한 사용자와의 상호작용과 같은 외부 사건에 의해 발생한다. 

**event**는 특정 사건이 일어났다는 것에 대한 알림이다. ex) 버튼 클릭  
대부분의 이벤트는 GUI와 같은 유저와의 상호작용에 의해서 발생하고, 이때 GUI를 widget이라고 한다.  
**event handler**는 이벤트가 발생하면 실행되는 코드이다. 

### java 예시

자바의 awt를 이용해서 GUI 프로그램을 만들 수 있다.  
이벤트는 이벤트 리스너를 통해 이벤트 핸들러와 연결된다  
이벤트가 발생하면 해당 이벤트 클래스의 인스턴스가 만들어진다.  
발생한 이벤트를 처리할 이벤트 리스너가 등록되어 있으면 이벤트 핸들러가 이벤트를 처리하고, 등록되어 있지 않다면 아무 작업도 하지 않는다.  
GUI 프로그램에 이벤트 핸들러를 등록하는 법은 다음과 같다

1. GUI 컴포넌트 생성
2. 등록하고 싶은 이벤트 리스너 인터페이스 구현
3. 구현 클래스를 해당 컴포넌트에 등록

예시 코드

```java
import java.awt.*;
import java.awt.event.*;

class MyAwt {
    public static void main(String[] args) {
        //1. 컴포넌트 생성
        Frame f = new Frame("Login");
        f.setSize(300,200);
        
        //3. 구현 클래스를 이벤트 리스너에 등록
        f.addWindowListener(new EventHandler());
        f.setVisible(true);
    }
}

//2. 이벤트 리스너 구현
class EventHandler implements WindowListener {
    //다른 메소드들을 아무 내용없이 구현...
    public void windowClosing(WindowEvent e) {
        e.getWindow().setVisible(false);
        e.getWindow().dispose();
        System.exit(0);
    }
}
```

먼저 Frame 컴포넌트를 만들고, 등록할 WindowListener 인터페이스를 구현한 EventHandler 클래스를 생성하였다.  
이벤트 리스너의 메소드는 해당하는 이벤트가 발생했을 때 실행된다  
창이 닫히는 이벤트인 windowClosing 메소드만 구현하였다.  
구현한 클래스를 `addWindowListener()`메소드를 통해 해당 컴포넌트에 등록하였다.

Adapter 클래스는 구현하고자 하는 리스너 인터페이스의 모든 메소드를 내용 없이 단순히 구현해놓은 클래스로 인터페이스를 모두 구현해야하는 번거로움을 해소해주는 클래스이다.



