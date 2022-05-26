# Support for Object-oriented programming

Object-oriented programming은 Smalltalk 80에서 제안된 개념이다.  
Object-oriented 방식을 지원하는 언어에서는 다음 3가지 특징을 지원해야 한다.  
- abstract data type (11장에서 다룸)
- inheritance
- dynamic binding

## Inheritance
기존 ADT를 조금 변형한 ADT를 재사용 할 필요가 있을 때 상속을 사용.  
상속(Inheritance)은 기존에 존재하던 ADT를 상속받은 ADT를 만들어 필요한 부분을 변형하거나 추가하여 재사용한다.  

다른 클래스를 상속받은 클래스를 derived class, subclass, child class 등으로 부르고,  
상속되는 클래스를 baseclass, superclass, parent class 등으로 부른다.  

클래스의 메소드를 message라고도 부르고, message의 모음을 message protocol, message intreface라고 한다.  

자식 클래스가 부모 클래스와 다른 점은 다음과 같다
- 새로운 변수/메소드 추가 가능
- 부모 클래스의 메소드를 오버라이딩 할 수 있음
- 부모 클래스의 private 변수/메소드는 자식 클래스에서 접근 불가

**override**는 부모 클래스의 메소드를 자식 클래스에 맞게 재정의 하는 것.  

클래스 변수는 클래스에 속하는 변수로 그 클래스에 단 하나만 존재한다.  
클래스 메소드는 객체 생성 없이도 호출할 수 있는 메소드이다.  

상속은 단일 상속과 다중 상속이 있으며 c++과 같은 언어는 다중 상속을 허용하지만 java와 같은 언어는 단일 상속만 허용한다.  

## Dynamic binding
polymorphism(다형성)의 일종으로 dynamic dispatch라고도 함.  
포인터가 현재 참조하고 있는 객체가 무엇인지에 따라 호출하는 메소드가 달라지게 하는 포인터를 **polymorphic reference**라고 한다.  
overriding 했을 때, 혹은 abstract 메소드를 구현할 때 적용된다.  

## Design issue

- 순수한 객체 지향 언어는 속도가 느리다
  - 따라서 primitive type이 존재하는 언어가 있음
- 서브 클래스를 서브 타입으로 여길 것인지?
  - 자바는 이를 허용함
- 다중 상속을 허용할 것인지?
  - 허용할 경우 diamond inheritance 문제가 발생할 수 있음
  - c++는 다중 상속을 허용함