# Abstract data types and Encapsulation constructs

## Abstraction
추상화는 가장 중요한 속성들만을 포함하여 나타내는 것이다.  
ex) 책을 추상화하면 책의 제목만 남는다.  
추상화를 함으로써 복잡함을 줄일 수 있다.  
추상화에는 두가지 종류가 있다.  
- process abstraction
- data abstraction

**process abstraction**은 처리 과정에 대한 추상화로, 서브 프로그램(함수)가 이것에 속한다.  
**data abstraction**은 데이터에 대한 추상화로, COBOL에서 recode 타입으로 처음 도입되어 C계열 언어에서 struct로 사용된다

## Abstract data type
Abstract data type은 data와 그 data를 처리하는 subprogram(함수)를 한데 묶어놓은 것. -> 객체 지향의 encapsulation  
Abstract data type은 객체 지향에서의 클래스와 같은 개념.  
접근 제한을 통해 불필요한 세부 사항을 숨긴다 -> 객체 지향의 information hiding  
Abstract data type의 인스턴스를 object(객체)라고 함.  
객체는 ADT에 있는 연산으로만 바뀔 수 있음.  

c++, objective-c와 같은 언어에서는 ADT의 명세 부분(specification) 과 구현 부분(implementation)부분을 구별하지만 java에서는 명세 부분이 따로 존재하지 않는다.  


