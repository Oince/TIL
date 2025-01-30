# Enum

## 개요

enum은 서로 관련된 상수를 편리하게 선언하기 위한 것이다. 여러 상수를 하나의 타입으로 제공해서 타입에 안전하게 상수를 사용할 수 있게 한다. 

## 만들어진 이유

enum이 없었을 때는 c언어와 유사하게 각각의 상수에 정수 리터럴을 지정해서 사용하였다.

```java
class PastEnum {
    public final int MON = 0;
    public final int TUE = 1;
    public final int WED = 2;
    public final int THU = 3;
    public final int FRI = 4;
    public final int SAT = 5;
    public final int SUN = 6;
}
```

이런 방식으로 상수를 관리할 경우 몇가지 단점이 있다. 

- 각각의 상수에 부여된 리터럴은 단순히 상수를 구별하기 위한 값으로 의미가 없음
- 다른 상수와 이름이 중복되는 경우 오류가 발생할 수 있음
- 상수는 정수이기 때문에 서로 비교되지 않아야 하는 상수끼리도 비교가 가능해짐

이런 단점을 해결하기 위해 java에서는 enum에 타입을 부여한다. 그리고 각 상수를 그 enum 객체로 선언해서 다른 enum 객체와 비교할 수 없게 하여 타입 안정성을 제공한다.

## 장점

- 타입 안정성을 보장함
  - 정의된 값만 사용할 수 있기 때문에 컴파일 타임에 타입을 체크하여 런타임 에러 방지
- 코드의 가독성이 높아짐
- 유지보수성이 좋음
  - enum에 새로운 상수를 추가할 경우 다른 코드를 변경하지 않고 수정 가능
- 인스턴스가 단 하나만 존재한다는 것이 보장됨
  - 리플렉션을 이용해서도 인스턴스를 생성할 수 없기 때문에 싱글톤 패턴을 구현하는데 사용하기도 함

## 사용하는 방법

enum은 다음과 같이 정의한다.

```java
enum Day {
    MON, TUE, WED, THU, FRI, SAT, SUN;
}
```

enum 키워드를 사용해서 선언하고, 중괄호 안에 사용할 상수들을 정의한다. 상수들은 대문자로 작성하고, 띄어쓰기는 언더바를 이용하는 것이 관례이다. 

사용하려면 `Day.MON`과 같이 enum이름.상수명으로 사용한다. enum 타입은 == 연산자를 지원하여 equals를 사용하는 것보다 더 빠르게 비교할 수 있다. 하지만 <, >와 같은 비교 연산자를 사용할 수 없으며 compareTo() 메서드를 사용해서 비교 가능하다. 또한 switch문의 조건식에도 사용 가능하며, 이 경우 enum 타입의 이름은 작성하지 않고 상수명만 작성할 수 있다.

```java
public class Main {
    public static void main(String[] args) {
        Day mon = Day.MON;
        Day tue = Day.TUE;

        if (mon == tue) 
            System.out.println("true");
        else 
            System.out.println("false");
        
        switch (mon) {
            case MON -> System.out.println("MON");
            case TUE -> System.out.println("TUE");
        }
    }
}

//출력 결과
/*
false
MON
*/
```

## 구조

모든 enum 타입은 상수 하나하나가 그 enum 타입의 객체이다. 각 상수의 값은 객체의 주소이기 때문에 == 연산자로 비교가 가능한 것이다. 위의 Day 타입을 클래스로 정의한다면 다음과 유사할 것이다.

```java
class Day {
    public static final Day MON = new Day("MON");
    public static final Day TUE = new Day("TUE");
    public static final Day WED = new Day("WED");
    public static final Day THU = new Day("THU");
    public static final Day FRI = new Day("FRI");
    public static final Day SAT = new Day("SAT");
    public static final Day SUN = new Day("SUN");
    
    private final String name;
    
    private Day(String name) {
        this.name = name;
    }
}
```

enum에 새로운 멤버를 추가하려면 그에 맞는 필드와 생성자를 추가해야 하고, 추상 메서드가 있다면 각 상수에 전부 구현해주어야 한다.

```java
enum Day {
    MON(false) {
        @Override
        public void greeting() {
            System.out.println("Good Monday!");
        }
    }, TUE(false) {
        @Override
        public void greeting() {
            System.out.println("Good Tuesday!");
        }
    },/*이하 생략*/;

    private final boolean weekend;

    Day(boolean weekend) {
        this.weekend = weekend;
    }
    public abstract void greeting();
}
```

모든 enum은 java.lang.Enum 추상 클래스를 상속받는다. Enum 클래스는 내부적으로 ordinal이란 정수로 각 상수에 번호를 부여해서 관리하며, compareTo() 메소드도 구현되어 있다. 다음은 Enum 추상 클래스의 일부분이다.

```java
public abstract class Enum<E extends Enum<E>>
        implements Constable, Comparable<E>, Serializable {

    private final String name;

    public final String name() {
        return name;
    }

    private final int ordinal;

    public final int ordinal() {
        return ordinal;
    }

    protected Enum(String name, int ordinal) {
        this.name = name;
        this.ordinal = ordinal;
    }
    
    public final int compareTo(E o) {
        Enum<?> other = (Enum<?>)o;
        Enum<E> self = this;
        if (self.getClass() != other.getClass() && // optimization
            self.getDeclaringClass() != other.getDeclaringClass())
            throw new ClassCastException();
        return self.ordinal - other.ordinal;
    }
}
```

## methods

Enum 클래스에서 제공하는 메서드는 다음과 같다.

| 메서드                                           | 설명                                                 |
| ------------------------------------------------ | ---------------------------------------------------- |
| Class<E> getDeclaringClass()                     | enum 타입의 class 객체 반환                          |
| String name()                                    | enum의 이름 반환                                     |
| int ordinal()                                    | 상수가 정의된 순서인 ordinal 반환                    |
| static T valueOf(Class<T> enumType, String name) | enumType에 지정된 enum에서 name과 일치하는 상수 반환 |

컴파일러는 모든 enum에 다음 메서드를 자동적으로 추가해준다.

| 메서드                        | 설명                                |
| ----------------------------- | ----------------------------------- |
| static T[] values()           | enum의 모든 상수를 배열에 담아 반환 |
| static T valueOf(String name) | 지정된 이름의 상수를 반환           |

## EnumSet

EnumSet은 enum에 사용하는 특별한 set이다. EnumSet은 Set 인터페이스를 구현한 AbstactSet 추상 클래스를 상속한다.

### 주의할 점

EnumSet 사용시 주의할 점은 다음과 같다.

- enum 값만 포함할 수 있고 그 값들은 전부 같은 enum 타입이어야 함
- null 추가 불가능
  - 추가할 시 NullPointerException 발생
- thread-safe 하지 않음
  - 필요시 외부에서 따로 동기화 처리를 해주어야 함
- 각 요소들은 ordinal 값에 따라 순서대로 저장됨

 ### 생성

EnumSet 자체도 추상 클래스이며, 정적 팩토리 메서드를 통해 생성할 수 있다. 생성자는 지원하지 않는다. 정적 팩토리 메서드의 종류는 다음과 같다

| 정적 팩토리 메서드                                   | 설명                                                         |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| noneOf(Class<E> elementType)                         | enum 타입으로 빈 EnumSet 생성                                |
| of(E e1), of(E e1, E e2), ... e5까지 있는 5개의 of() | 지정한 상수들로 EnumSet 생성                                 |
| of(E first, E... rest)                               | 가변 매개변수를 사용한 of(). 배열을 생성하기 때문에 속도가 느림. 6개 이상의 파라미터를 넘길 때만 사용 |
| allOf(Class<E> elementType)                          | enum 타입에 있는 모든 상수들로 EnumSet 생성                  |
| copyOf(Collection<E> c)                              | Collection 객체로 EnumSet 생성                               |
| complementOf(EnumSet<E> s)                           | 매개 변수로 넘어간 EnumSet의 차집합 생성                     |
| range(E from, E to)                                  | from 부터 to 까지의 상수들로 EnumSet 생성                    |

### 구현

EnumSet에는 2가지의 구현체가 있다.

- RegularEnumSet
  - enum 상수의 개수가 64개 이하인 경우 생성되는 구현체
- JumboEnumSet
  - 개수가 64개 보다 많을 경우 생성되는 구현체

RegularEnumSet은 하나의 long 타입 변수 비트 연산을 사용해서 enum 상수들을 저장한다. enum 상수의 ordinal 값에 해당하는 비트를 1로 바꾸어서 상수를 저장한다. 읽을 때도 마찬가지로 ordinal 값 만큼 비트 쉬프트 연산 후에, 해당하는 비트의 값이 1인지를 확인하는 방식이다.

JumboEnumSet은 하나의 변수가 아닌 long 타입 배열을 선언하여 관리한다. 배열의 첫 번째 요소는 처음 64개 상수, 그 다음은 두 번째 64개 상수를 저장하는 방식이며, 로직은 RegularEnumSet과 유사하게 작동한다.

다음은 RegularEnumSet의 add 메서드이다.

```java
public boolean add(E e) {
    typeCheck(e);

    long oldElements = elements;
    elements |= (1L << ((Enum<?>)e).ordinal());
    return elements != oldElements;
}
```

위 코드를 보면 변수 elements에 ordinal 값을 비트 연산하여 저장하는 것을 볼 수 있다.

### 장점

위에 설명했듯 EnumSet은 비트 연산을 통해 데이터를 저장한다. 비트 연산은 속도가 매우 빠르고, 일정한 시간 안에 실행된다. EnumSet은 값이 예측 가능한 순서로 저장되면서 하나의 비트만 체크하면 되기 때문에, 버킷을 찾기 위해 hashcode를 계산해야 하는 HashSet과 같은 다른 Set보다 훨씬 빠르다.

