# Exception handling

## 계층 구조

![](https://madplay.github.io/img/post/2019-03-02-java-checked-unchecked-exceptions-1.png)

java에서는 실행시 발생할 수 있는 프로그램 오류를 Error와 Exception으로 구분하며, 둘 모두 Throwable 클래스를 상속받는다.

### Error

- 복구할 수 없는 심각한 오류
- 발생하면 프로그램이 비정상적으로 종료됨
- ex) OutOfMemoryError(메모리 부족), StackOverflowError(스택 오버플로우 발생) 등

### Exception

- 프로그램의 코드로 수습할 수 있는 오류
- 적절한 예외 처리 코드를 작성해놓으면 비정상적인 종료를 막을 수 있음

Exception은 크게 RuntimeException과 그 이외의 예외들로 나눌 수 있다.

- RuntimeException
  - 주로 프로그래머의 실수에 의해서 발생할 수 있는 예외들
  - unchecked exception
  - ex) NullPointerException(값이 null인 참조 변수를 참조), ArithmeticException(정수를 0으로 나눔), ArrayIndexOutOfBound(배열의 범위를 벗어난 값 접근) 등
- 이외의 Exception 클래스를 상속받는 예외들
  - 외부의 영향으로 발생할 수 있는 예외로 주로 사용자들의 동작에 의해서 발생함
    - 파일 입출력, 네트워크, DB 연결 등에서 발생
  - checked exception
  - IOException(파일 입출력 오류), ClassNotFoundException(존재하지 않는 클래스) 등

#### checked exception vs unchecked exception

checked exception은 예외 처리가 강제되는 예외이다. try-catch 로 예외를 잡아서 처리하거나 throws로 호출한 쪽에게 예외처리를 넘김을 명시해야 하며, 그렇지 않으면 컴파일 에러가 발생한다.

unchecked exception은 명시적인 예외 처리가 강제되지 않는 예외이다. RuntimeException은 주로 프로그래머의 실수에 의해서 발생하고 코드 수정으로 해결할 수 있는 예외이기 때문에 처리를 강제하지 않는다. 만약 강제되었다면 참조 변수에 접근할 때나 배열에 접근할 때 NullPointerException, ArrayIndexOutOfBound 예외에 대한 처리를 전부 작성해야 했을 것이다.

checked exception은 복구할 가능성이 있는 예외들에 대해 처리를 강제해서 더 견고한 프로그램을 작성하기 위해 도입되었다. 하지만 예외를 복구할 수 없는 경우가 대다수이기 때문에 최근에는 checked exception을  unchecked exception으로 래핑해서 다시 던지는 방식으로 예외를 처리한다.

## 처리 방법

### try-catch

try-catch 문은 예외를 처리하기 위한 기본적인 방법이다. 구조는 다음과 같다

```java
try {
    //예외가 발생할 가능성이 있는 코드
} catch(Exception1 e1) {
    //Exception1이 발생했을 때 실행하는 코드
} catch(Exception2 e2) {
	//Exception2이 발생했을 때 실행하는 코드
} catch(ExceptionN eN) {
    //ExceptionN이 발생했을 때 실행하는 코드
}
```

try-catch 문의 실행 흐름은 다음과 같다

- try 블록 내부에서 예외가 발생할 경우
  - 발생한 예외와 일치하는 catch 블록을 선언된 순서대로 찾음
    - 있으면 catch문 실행하고 try-catch 이후의 문장 실행
    - 없으면 예외가 처리되지 못함
  - try 블록에서 예외가 발생한 이후의 문장은 실행되지 않음
- 발생하지 않은 경우
  - 전체 try-catch 문을 건너 뛰고 다음 문장 실행

catch 문을 찾을 때, 발생한 예외와 catch 문에 선언된 예외를 instanceof 연산자를 통해 타입이 일치하는지 찾는다. 따라서 발생한 예외가 catch 문에 선언된 예외의 자식 클래스여도 그 catch 문으로 처리된다.

```java
try {
    int a = 1 / 0;
} catch (Exception e) {
    System.out.println("divided by zero");
}
//실행 결과
/*
divided by zero
*/
```

위 코드는 0으로 나누었기 때문에 ArithmeticException이 발생하는데, catch 블록에서 Exception 클래스를 지정해도 예외를 잡아서 처리하는 것을 볼 수 있다.

여러개의 catch 블록을 작성하였을 경우에 상위 타입의 예외를 밑에 두고, 하위 타입의 예외를 위에 두어야 한다. 상위 타입의 예외를 위에 두면 하위 타입의 예외까지도 처리하기 때문에 처리를 하는 의미가 없어진다. 만일 이렇게 할 경우 컴파일 에러가 발생한다.

여러개의 catch 블록 을 하나로 합쳐서 사용할 수 있으며, 이를 멀티 catch 블록이라고 한다. 이를 사용하면 여러개의 예외를 하나의 catch 블록으로 모아서 처리할 수 있다.

```java
try	{
    ...
} catch (NullPointerException | IllegalArgumentException e) {
	...
}
```

### throw

throw를 이용하면 예외를 의도적으로 발생시킬 수 있다.

```java
try {
    throw new RuntimeException("throw RuntimeException");
} catch (RuntimeException e) {
    System.out.println(e.getMessage());
}
```

### throws

throws를 사용하면 메서드를 호출한 쪽에 예외 처리를 넘길 수 있다. 

```java
public class Main {
    public static void main(String[] args) {
        try {
            String str = method1();
            System.out.println(str);
        } catch (IOException e) {
            System.out.println("파일이 존재하지 않습니다.");
        }
    }

    public static String method1() throws IOException {
        return Files.readString(Path.of("test.txt"));
    }
}
```

위 코드는 파일을 읽어서 파일의 내용을 String으로 반환하는 코드이다. throws를 이용해서 method1() 메서드를 호출한 main 메서드에서 예외 처리를 넘겼다. main 메서드에서 try-catch를 사용해서 넘어온 IOException을 처리한다. 

이는 단순히 호출한 메서드에 예외 처리를 떠넘기는 것이다. 결국 try-catch문으로 처리해야 한다는 뜻이다. 예외가 발생한 메서드 내에서 처리 가능한 예외는 그 메서드 내부에서 직접 처리하고, 내부에서 처리할 수 없는 경우엔throws를 이용해서 호출한 쪽에 예외 처리를 넘기는 방식으로 사용한다.

throws를 사용하는 경우 관례적으로 checked 예외만 작성하고 unchecked 예외는 작성하지 않는다.

### finally

finally 블록은 예외 발생 여부에 관계 없이 실행되어야 하는 코드를 작성하는 곳이다. try-catch문 이후에 선택적으로 사용 가능하다.

```java
try {
	//예외가 발생할 가능성이 있는 코드
} catch(Exception e) {
    //Exception이 발생했을 때 실행되는 코드
} finally {
    //예외 발생 여부에 관계 없이 실행되어야 하는 코드
}
```

finally 블록은 try-catch문의 마지막에 위치해야 한다. 예외 발생 시 try -> catch -> finally 순으로 실행된다. 예외가 발생하지 않으면 try -> finally 순으로 실행된다. try 블록 또는 catch 블록 내부에 return문이 있을 경우에도 finally 블록이 먼저 실행된 후에 return 된다.

### try-with-resources

다음과 같은 코드가 있다고 하자

```java
public class Main {
    public static void main(String[] args) {
        FileWriter file = null;
        try {
            file = new FileWriter("test.txt");
            file.write("test");
        } catch (IOException e) {
            throw new RuntimeException(e);
        } finally {
            file.close();
        }
    }
}
```

이 코드는 파일을 읽어오는 코드이다. 파일을 다 읽은 후에 finally를 통해 파일을 닫아주려고 한다. 하지만 이 코드는 파일을 닫는 close() 메서드 실행 시 예외가 발생할 수 있다는 문제가 있다. 따라서 수정하면 다음과 같다

```java
public class Main {
    public static void main(String[] args) {
        FileWriter file = null;
        try {
            file = new FileWriter("test.txt");
            file.write("test");
        } catch (IOException e) {
            throw new RuntimeException(e);
        } finally {
            try {
                file.close();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
```

finally 블록 내부에서 다시 try-catch로 예외를 처리해준 코드이다. 이 코드는 동작은 하지만 가독성이 매우 좋지 않다.

이런 문제를 해결하기 위해서 try-with-resources문이 추가되었다. try에 자원을 설정할 수 있고, 블록이 끝나면 자동으로 자원을 자동으로 회수해주는 역할을 한다. try-with-resources를 적용한 코드는 다음과 같다.

```java
public class Main {
    public static void main(String[] args) {
        try (FileWriter file = new FileWriter("test.txt")) {
            file.write("test");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
```

괄호 안에 회수되어야 할 자원을 적어두고, try 블록이 끝나면 자동적으로 close()가 호출된다. 자동으로 close() 메서드가 호출되려면 지정된 클래스가 AutoCloseable 인터페이스를 구현해야 한다.

## Custom exception

필요에 따라서 사용자 정의 예외 클래스를 정의할 수 있다. 

```java
public class NotFoundException extends RuntimeException {

    private int errorCode;

    public NotFoundException(String message) {
        this(message, 100);
    }

    public NotFoundException(String message, int errorCode) {
        super(message);
        this.errorCode = errorCode;
    }

    public int getErrorCode() {
        return errorCode;
    }
}
```

RuntimeException의 상위 클래스인 Throwable 클래스에는 생성시에 message나 Throwable 객체를 받아서 저장할 수 있는 생성자가 있다. 이들을 저장하려면 생성자를 추가해서 저장할 수 있다. 뿐만 아니라 멤버 변수도 추가할 수 있기 때문에 필요에 따라서 필드를 정의할 수 있다. 위 코드에서는 에러 코드를 필드로 추가하였다.

checked 예외가 필요한 경우 Exception을 상속하고, unchecked 예외가 필요한 경우에는 RuntimeException을 상속받는다. 최근에는 예외 처리를 선택적으로 할 수 있도록 RuntimeException을 상속받는 경우가 많다.

## chained exception

예외 A가 예외 B를 발생시켰을 때 A를 B의 원인 예외라고 한다. initCause() 메서드나 생성자를 이용해 원인 예외를 새로 발생한 예외에 등록할 수 있다.

```java
public class Main {
    public static void main(String[] args) {
        try {
            throw new IOException();
        } catch (IOException e) {
            NotFoundException e1 = new NotFoundException("파일 찾기 실패");
            //initCause 이용
            e1.initCause(e);
            
            //또는 생성자를 이용해서 지정 가능
          	//NotFoundException e1 = new NotFoundException("파일 찾기 실패", e);
            
            throw e1;
        }
    }
}
```

위 코드는 initCause() 메서드를 이용해서 try 블록에서 발생한 IOException을 NotFoundException의 원인 예외로 지정한 코드이다. 

이렇게 처리하는 이유는 여러 예외를 하나의 큰 분류로 묶어서 다루기 위해서이다. 원인 예외를 지정하지 않고 새로운 예외를 발생시키면 실제 발생한 예외가 무엇인지 알 수 없다는 문제가 생긴다. 이것을 해결하기 위해 예외가 원인 예외를 포함할 수 있게 해서 새로운 예외를 던지더라도 실제 발생한 예외를 알 수 있도록 했다.

또한 checked 예외를 unchecked 예외로 바꾸기 위한 목적도 있다. checked 예외가 발생해도 예외를 처리할 수 없는 상황이 많아졌기 때문에 발생한 checked 예외를 unchecked 예외로 바꾸어서 처리한다. 이렇게 하면 의미없는 try-catch문이 없어지고 예외를 선택적으로 처리할 수 있게 된다.
