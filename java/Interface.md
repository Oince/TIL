# Interface

## 개요

인터페이스는 일종의 추상클래스이다. 추상클래스와 달리 몸통이 있는 메서드를 가질 수 없다. 추상메서드와 상수만을 멤버로 가진다. 클래스를 작성할 때의 기본 설계도와 같으며 다른 클래스들 사이에서 매개해주는 중간 역할을 한다.

## 정의하는 방법

클래스를 작성하는 것과 유사하지만 class 대신 interface 키워드를 이용한다.

인터페이스의 멤버는 제약사항이 존재한다

- 모든 필드는 public static final이며 생략 가능하다
- 모든 메서드는 public abstract이며 생략 가능하다
  - default, static, private 메서드는 예외, 후술

모든 멤버에 적용되어야 하는 키워드들이기 때문에 생략 시 컴파일러가 자동으로 추가해준다.

```java
public interface Mouse {

    //밑의 메서드들은 전부 public abstract가 생략되어 있음
    void leftClick();
    void rightClick();
    void move();
    void upWheel();
    void downWheel();
}
```

## 구현하는 방법

인터페이스 그 자체로는 바로 인스턴스를 생성할 수 없다. 인스턴스를 생성하기 위해서 인터페이스에 정의된 추상 메서드의 몸통을 구현하는 클래스를 만들어야 한다. 클래스가 특정 인터페이스를 구현하려면 `implements` 키워드를 사용한다. 인터페이스를 구현하는 클래스는 선언된 모든 추상 메서드를 구현해야 한다.

```java
public class SamsungMouse implements Mouse {

    @Override
    public void leftClick() {
        System.out.println("left click");
    }

    @Override
    public void rightClick() {
        System.out.println("right click");
    }

    @Override
    public void move(int value) {
        System.out.println("move: " + value);
    }

    @Override
    public void upWheel() {
        System.out.println("up wheel");
    }

    @Override
    public void downWheel() {
        System.out.println("down wheel");
    }
}

```

구현하는 인터페이스의 메서드 중 일부분만 구현한다면, 구현되지 않은 추상 메서드가 존재하기 때문에 추상클래스로 선언해야 한다.

```java
//추상 클래스
public abstract class SamsungMouse implements Mouse {

    @Override
    public void leftClick() {
        System.out.println("left click");
    }

    @Override
    public void rightClick() {
        System.out.println("right click");
    }
}
```

익명 클래스를 사용하면 일회용으로 인터페이스를 구현해서 사용할 수 있다

```java
Mouse mouse = new Mouse() {
    @Override
    public void leftClick() {
        System.out.println("left click");
    }

    @Override
    public void rightClick() {
        System.out.println("right click");
    }
	//이하 생략
}
```

## 레퍼런스를 통해 구현체를 사용하는 방법

다형성을 이용해서 인터페이스의 참조 변수로 인터페이스를 구현한 클래스의 인스턴스를 참조할 수 있다

```java
public class Main {
    public static void main(String[] args) {
        Mouse mouse = new SamsungMouse();
        mouse.leftClick();
        mouse.rightClick();
    }
}

//실행 결과
left click
right click
```

클래스를 직접 참조하면, 클래스의 변경이 있을 때 참조하는 쪽에서도 변경이 필요해진다. 인터페이스를 이용해 참조하면, 실제 구현 클래스의 변화가 있어도 객체간의 통신은 인터페이스에 정의된 메서드로만 이루어지기 때문에 참조하는 쪽에서는 변경이 필요하지 않게 된다. 

이후에 요구사항이 변경되어 다른 로직으로 작동해야 한다고 했을 때도, 인터페이스가 구현된 다른 클래스를 넣어주면 원본 코드의 수정 없이 로직을 변경할 수 있다. 예를 들어 위의 코드에서 SamsungMouse가 아닌 LGMouse를 대신 넣어줘도 클릭 기능을 수행하는 코드가 변경되지 않는다.

한마디로 객체를 사용하는 방식인 인터페이스만 알고 있으면 사용하는 쪽에서 구현 클래스가 무엇이는 신경쓰지 않는다는 것이다.

## 상속

인터페이스는 다른 종류의 인터페이스를 상속받을 수 있으며 조상 인터페이스의 모든 멤버를 상속받는다. 

```java
interface Animal {
    void eat();
}

//Animal 인터페이스 상속
interface Flyable extends Animal {
    void fly();
}

//Flyable 인터페이스에 eat도 포함되어 있음
class Bird implements Flyable {
    @Override
    public void fly() {
        System.out.println("bird fly");
    }

    @Override
    public void eat() {
        System.out.println("bird eat");
    }
}
```

자바에서는 다중 상속을 지원하지 않지만, 인터페이스는 여러개를 구현할 수 있다. 필드의 이름이 겹치는 경우에, 인터페이스의 필드는 static 상수이기 때문에 독립적으로 접근 가능하다. 메소드의 이름이 겹치는 경우에도 어짜피 클래스에서 오버라이딩해서 구현해야 하기 때문에 문제가 없다.

```java
interface Animal {
    void move();
    void eat();
}

interface Swimmable {
    void swim();
    void eat();
}

class Duck implements Animal, Swimmable {
    @Override
    public void move() {
        System.out.println("duck move");
    }
    
    @Override
    public void swim() {
        System.out.println("duck swim");
    }

    //구현한 두 인터페이스에 모두 eat 메서드가 있지만 문제 없이 작동함
    @Override
    public void eat() {
        System.out.println("duck eat");
    }
}
```

## Default method

클래스와 달리 인터페이스에는 새로운 메서드를 추가하는 것이 간단한 일이 아니다. 인터페이스의 모든 메서드는 하위 클래스들에 의해 구현되어야 한다. 새 메서드가 추가되면 그 인터페이스를 구현하는 모든 클래스를 변경해야 한다. 이는 확장에는 열려 있고 변경에는 닫혀있어야 한다는 OCP 원칙을 위반한 것이다. 

이를 해결하기 위해 java 8부터 default 메서드가 추가되었다. default 메서드는 메서드 앞에 `default`키워드를 붙여서 만든다. default 메서드는 인터페이스 내부에 선언되며, 구현부를 가질 수 있는 메서드이다. 구현부를 가지기 때문에 하위 클래스에서 해당 메서드를 가져다가 사용할 수 있으며, 오버라이딩해서 사용하는것도 가능하다. 

구현한 인터페이스에 있는 default 메서드의 이름이 다른 인터페이스나 조상 클래스의 메서드 이름과 같아 충돌하는 경우 다음과 같은 방식으로 처리된다

- 여러개의 인터페이스들이 같은 이름의 default 메서드를 가지고 있는 경우
  - 구현 클래스에서 default 메서드를 오버라이딩 해야함
  - 오버라이딩 하지 않을 경우 컴파일 에러
- 조상 클래스의 메서드와 이름이 같은 경우
  - 조상 클래스의 메서드가 상속되고 default 메서드는 무시됨

```java
interface Mouse {

    //default 메서드
    default void leftClick() {
        System.out.println("left click");
    }
    default void rightClick() {
        System.out.println("right click");
    }
    void move(int value);
    void upWheel();
    void downWheel();
}

class LGMouse implements Mouse {
    
    //default 메소드는 구현하지 않아도 에러가 발생하지 않음
    
    //새로 오버라이딩하여 사용 가능
    @Override
    public void rightClick() {
        System.out.println("LG mouse right click");
    }

    @Override
    public void move(int value) {
        System.out.println("move: " + value);
    }

    @Override
    public void upWheel() {
        System.out.println("up wheel");
    }

    @Override
    public void downWheel() {
        System.out.println("down wheel");
    }
}

class Main {
    public static void main(String[] args) {
        Mouse mouse = new LGMouse();
        //default 메소드 사용
        mouse.leftClick();
        mouse.rightClick();
    }
}

//출력 결과
//left click
//LG mouse right click
```

## static method

default 메서드와 같이 java 8부터 추가된 메서드이다. static 메서드는 인스턴스와 독립적인 메서드이기 때문에 추가되지 못할 이유가 없었지만, 인터페이스의 모든 메서드는 추상 메서드이어야 한다는 규칙을 지키기 위해서 지원되지 않았다. 때문에 인터페이스와 관련된 static 메서드는 따로 클래스를 만들어서 구현했었다. Collections 클래스가 그 예시로, collection에 관한 static 메서드를 모아놓은 클래스이다.

클래스의 static 메서드와 유사하게 작동하며 인스턴스 생성 없이 실행 가능하다. static 메서드는 구현 클래스에서 오버라이딩할 수 없다.

```java
interface Calculator {
    static int add(int a, int b) {
        return a + b;
    }

    static int sub(int a, int b) {
        return a - b;
    }
}

class Main {
    public static void main(String[] args) {
        System.out.println(Calculator.add(1, 2));
        System.out.println(Calculator.sub(1, 2));
    }
}

//출력 결과
//3
//-1
```

## private method

java 9 버전부터 추가된 메서드이다. default, static 메서드가 생긴 후로 이런 메서드를 사용할 때 로직의 공통 부분을 따로 메서드로 만들어서 재사용하기 위해 추가되었다. private 메서드는 인터페이스 내부의 default 메서드나 static 메서드에서 사용된다. 구현부를 반드시 가져야 하고, 구현 클래스에서 사용하거나 오버라이딩 할 수 없다.

```java
interface HelloWorld {

    default void print() {
        helloWorld();
    }
    
    private void helloWorld() {
        System.out.println("Hello World!");
    }
}

class HelloWorldImpl implements HelloWorld {}

class Main {
    public static void main(String[] args) {
        HelloWorld helloWorld = new HelloWorldImpl();
        helloWorld.print();
        //private 메서드는 구현 클래스에서 사용할 수 없음
        //helloWorld.helloWorld();
    }
}
```