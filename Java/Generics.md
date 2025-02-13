# Generics

## 제네릭이란?

제네릭은 다양한 타입의 객체들을 다루는 메서드나 컬렉션 클래스에 컴파일 시의 타입 체크를 해주는 기능이다.

제네릭이 없었을 때는 여러 타입을 다루기 위해서 Object 타입을 사용했었다. Object 타입을 사용하면 원하는 객체로 변환하기 위해서 일일이 캐스팅을 해야 하며, 다른 타입이 들어가 있을 수도 있기 때문에 런타임 예외가 발생할 수도 있다.

 이런 단점을 해결하기 위해 제네릭이 추가되었다. 제네릭은 사용할 타입을 지정할 수 있으며 컴파일 타임에 타입을 체크한다. 컴파일 타임에 체크하기 때문에 런타임 예외를 방지할 수 있다. 또한 타입이 지정되어 있기 때문에 타입 체크와 캐스팅을 생략할 수 있어 코드가 간결해진다.

## 제네릭 클래스 선언

제네릭 클래스는 다음과 같이 선언한다.

```java
public class Box<T> {
    T item;

    void setItem(T item) {
        this.item = item;
    }

    T getItem() {
        return item;
    }
}
```

T는 타입 변수이다. 이 제네릭 클래스에서 사용할 타입을 의미한다. 다른 문자를 사용하도 상관 없으며, 각 상황에 맞는 의미있는 문자를 사용하는 것이 좋다. 예전 방식에서는 Object 객체를 사용했었는데, 제네릭을 사용하면 타입 변수를 지정해서 원하는 타입으로 사용할 수 있다.

생성 시 T에 해당하는 타입을 지정해주어야 한다. 지정된 타입 이외의 타입으로 호출했을 때는 컴파일 에러가 발생한다.

```java
Box<String> box1 = new Box<String>();
//box.setItem(Integer.valueOf(1)); 컴파일 에러 발생, String이어야 하는데 Integer을 넘김
String item = box1.getItem(); // 형변환이 필요 없음
```

이전 코드와 호환을 위해서, 타입을 지정하지 않고 제네릭 클래스를 생성할 수 있다. 이를 원시 타입이라고 한다. 하지만 안전하지 않기 때문에 경고가 발생한다. 타입을 지정하지 않으면 T는 Object 타입으로 간주된다. T를 Object 타입으로 지정하면 타입을 지정한 것이기 때문에 경고가 발생하지 않는다.

```java
Box box = new Box(); //경고 발생
```

Box<T>를 제네릭 클래스라고 부른다. T는 타입 변수 혹은 타입 매개변수라고 한다. Box 클래스는 원시 타입이라고 한다. 타입 매개변수에 타입을 지정하는 것을 제네릭 타입 호출이라고 하며, 지정된 타입을 매개변수화된 타입(대입된 타입)이라고 한다. 컴파일 후에 제네릭 클래스는 각각의 원시 타입으로 변환되고 제거된다.

### 주의할 점

제네릭 클래스는 static 멤버에 타입 변수를 사용할 수 없다. 타입 변수는 인스턴스 변수로 취급된다. static 멤버는 모든 인스턴스에서 동일해야 하는데 타입 변수를 사용하면 타입의 종류에 따라 달라지기 때문이다.

또한 new 연산자를 사용해서 T의 인스턴스를 만들 수 없다. new 연산자를 사용하려면 컴파일 타임에 타입에 대한 정보를 알아야 하는데 알 수 없기 때문이다. 같은 이유도 instanceof 연산자도 사용이 불가능하다. 인스턴스를 생성할 필요가 있다면 Reflection의 newInstance()를 사용하거나 Object 객체를 생성해서 캐스팅 해서 사용해야 한다.

## 제네릭 클래스 생성과 사용

생성할 때 참조 변수와 생성자의 타입은 같아야 한다. 같지 않으면 에러가 발생한다. 타입 변수가 상속 관계여도 대입이 불가능하다. 제네릭 클래스 자체가 상속 관계에 있고, 대입된 타입이 같으면 대입할 수 있다. 또한 생성자의 타입을 생략할 수 있다. 참조 변수의 타입을 보고 컴파일러가 추정할 수 있기 때문이다.

```java
Box<Apple> box = new Box<Apple>(); 			//같은 타입이어야 함
//Box<Fruit> box1 = new Box<Apple>(); 		//에러 발생
Box<Apple> box2 = new FruitBox<Apple>(); 	//상속 관계여서 대입 가능
//Box<Fruit> box3 = new FruitBox<Grape>();	//상속 관계여도 타입이 다르면 대입 불가
Box<Apple> box4 = new FruitBox<>(); 		//타입 생략 가능
```

메서드에서 타입 변수를 사용했을 때 대입된 타입 변수와 다른 타입을 받을 수 없다. 하지만 다형성이 적용되기 때문에 대입된 타입의 자식 타입은 매개변수로 할 수 있다.

```java
Box<Apple> box = new Box<>();
Box<Fruit> fruitBox = new Box<>();

//box.setItem(new Grape()); 에러 발생, 다른 타입
fruitBox.setItem(new Grape()); //정상 동작, Fruit의 자식인 Grape이기 때문
```

## 제한된 제네릭 클래스

타입 변수에 지정할 수 있는 타입을 제한할 수 있다.

```java
class FruitBox<T extends Fruit> {}
```

**extends **키워드를 이용하면 지정된 타입의 자식 타입만을 대입할 수 있게 한다. 위의 FruitBox에는 Fruit 객체와 그의 자식 타입(Apple, Grape)만 지정할 수 있다. 

자식 타입에는 인터페이스 구현도 포함된다. 인터페이스의 경우에도 implements 키워드가 아닌 extends 키워드를 사용한다. 상속과 구현 모두 필요한 타입을 지정할 때는 & 기호는 이용해서 연결한다.

```java
class FruitBox<T extends Fruit & Eatable> {}
```

## 와일드 카드

### 공변과 불공변

- 공변: S가 T의 하위 타입이면, S[]는 T[]의 하위 타입이다.
  - 배열은 공변적이다.

- 반공변: S가 T의 하위 타입이면, T[]는 S[]의 하위 타입이다.
- 불공변: `List<S>`와 `List<T>`는 관계가 없다. 
  - 제네릭은 불공변이다. `List<String>`과 `List<Object>`는 아예 다른 타입으로 서로 관계가 없다.


### 예시

다음과 같이 FruitBox를 넘기면 Juice를 만들어서 넘겨주는 메서드가 있다고 하자.

```java
public class Juicer {
    static Juice makeJuice(FruitBox<Fruit> box) {
        String tmp = "";
        for (Fruit fruit : box.list) {
            tmp += fruit + " ";
        }
        return new Juice(tmp);
    }
}

class Juice {
    String name;
    public Juice(String name) {
        this.name = name;
    }
}
```

Juicer 클래스는 제네릭 클래스가 아니기 때문에 타입 변수를 사용할 수 없다. 이 상황에서 제네릭 클래스를 파라미터로 넘기게 되면 특정 타입을 지정해주어야 한다. 제네릭은 불공변이기 때문에 타입이 Fruit로 고정되면 Fruit이외의 타입이 들어오면 에러가 발생한다. 따라서 여러개의 타입에 대해 전부 메서드를 작성해야 한다.

```java
public class Juicer {
    static Juice makeJuice(FruitBox<Fruit> box) {
        String tmp = "";
        for (Fruit fruit : box.list) {
            tmp += fruit + " ";
        }
        return new Juice(tmp);
    }
    static Juice makeJuice(FruitBox<Apple> box) {
        String tmp = "";
        for (Fruit fruit : box.list) {
            tmp += fruit + " ";
        }
        return new Juice(tmp);
    }
}
```

하지만 이렇게되면 에러가 발생한다. 제네릭 타입이 다른 것만으로는 오버로딩이 되지 않기 때문이다. 제네릭 타입은 컴파일 후에 제거되기 때문에, 위의 코드는 중복 정의된 메서드가 된다. 

이를 해결하기 위해서 와일드 카드가 도입되었다. 와일드 카드는 제네릭에 공변성과 반공변성을 추가해준다.

  와일드 카드는 `?` 기호로 표시하고, 다음과 같이 제한을 걸 수 있다.

- <?> : 제한 없음. <? extends Object>와 동일
- <? extends T>: 와일드 카드의 상한 제한. T와 그 자식 타입만 가능
- <? super T>: 와일드 카드의 하한 제한. T와 그 부모 타입만 가능

와일드 카드를 사용해서 코드를 변경하면 다음과 같다. `<? extends Fruit>`를 사용해서 Fruit의 자식 타입도 파라미터로 받을 수 있도록 변경하였다.

```java
public class Juicer {
    static Juice makeJuice(FruitBox<? extends Fruit> box) {
        String tmp = "";
        for (Fruit fruit : box.list) {
            tmp += fruit + " ";
        }
        return new Juice(tmp);
}
```

## 제네릭 메서드

제네릭 메서드는 메서드의 선언부에 제네릭 타입이 선언된 메서드이다. 

제네릭 메서드에 선언된 T는 제네릭 클래스에 정의된 것과는 전혀 상관없는 별개의 변수이다. 제네릭 메서드에 선언된 제네릭 타입은 지역 변수를 선언한 것과 같다고 생각하면 이해가 쉽다. 이 메서드 안에서만 사용할 것이기 때문에 static이어도 상관이 없다.

```java
public class Juicer {
    static <T extends Fruit> Juice makeJuice(FruitBox<T> box) {
        String tmp = "";
        for (Fruit fruit : box.list) {
            tmp += fruit + " ";
        }
        return new Juice(tmp);
    }
}
```

위의 코드는 제네릭 메서드를 적용한 메서드이다. 사용할 타입 변수를 메서드 앞에 미리 선언해두고 사용한다. 매개변수의 타입이 복잡하거나 같은 타입이 반복되는 경우에 유용하게 사용할 수 있다.

제네릭 메서드를 호출할 때는 타입 변수에 타입을 대입해야 한다. 하지만 컴파일러가 타입을 추정할 수 있기 때문에 대부분의 경우 생략한다.

```java
FruitBox<Fruit> fruitBox = new FruitBox<>();
Juicer.<Fruit>makeJuice(fruitBox);
Juicer.makeJuice(fruitBox);	//타입 생략 가능
```

## Erasure

컴파일러는 컴파일 과정에서 제네릭 타입을 이용해서 소스 파일을 체크하고, 필요한 곳에 캐스팅을 넣어준다. 그리고 제네릭 타입을 제거한다. 컴파일 결과물은 .class 파일에는 제네릭 타입에 대한 정보가 없다. 이렇게 하는 이유는 제네릭이 도입되기 전에 작성된 코드와 호환성을 유지하기 위함이다.

과정은 다음과 같다

1. 제네릭 타입의 경게를 제거한다

   - 제네릭 타입이 `<T>`이면 Object로, `<T extends Fruit>`면 Fruit로 치환된다

   - ```java
     class Box<T extends Fruit>{
     	void add(T t){
     		...
     	}
     }
     ```

   - ```java
     class Box{
     	void add(Fruit t){
     		...
     	}
     }
     ```

2. 제거 후에 타입이 일치하지 않으면 캐스팅을 추가한다

   - ```java
     T get(int i){
     	return list.get(i);
     }
     ```

   - ```java
     Fruit get(int i){
     	return (Fruit)list.get(i);
     }
     ```

3. 와일드 카드가 포함되어 있는 경우도 캐스팅을 추가한다

   - ```java
     static Juice makeJuice(FruitBox<? extends Fruit> box){
     	String tmp = "";
     	for(Fruit f : box.getList()) temp += f + " ";
     	return new Juice(temp);
     }
     ```

   - ```java
     static Juice makeJuice(FruitBox box){
     	String tmp = "";
     	Iterator it = box.getList().iterator();
     	while(it.hasNext()){
     		tmp += (Fruit)it.next() + " " ;
     	}
     	return new Juice(temp);
     }
     ```

   - 
