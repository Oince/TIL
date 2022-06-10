# Subprograms

함수는 처리 과정을 추상화한 것 (process abstraction)

## 기본

- **active**
  - 함수가 실행되었지만 종료되지 않은 상태
- activation record
  - active된 함수의 정보가 저장되는 공간
- subprogram header
  - 함수 정의의 첫 부분
  - API라고도 함

- **parameter profile**
  - 파라미터의 개수, 순서, 타입 등을 나타냄
- protocol
  - parameter profile + 리턴타입
- **formal parameter**
  - 함수 헤더에 정의된 파라미터
- **actual parameter**
  - 함수 호출시 넘겨주는 파라미터
- positional parameter
  - 파라미터를 위치로 결정하는 방식
- keyword parameter
  - 파라미터를 이름으로 명시하는 방식, 기본값 지정 가능
  - readability를 위해 사용

subprogram에는 두가지 종류가 있음

- **procedure**
  - 리턴값이 없음
  - 리턴값이 없기 때문에 전역변수, 혹은 call by reference로 넘어온 파라미터를 수정하는 방식으로 결과를 냄
    - **side effect** 발생 
  - 함수형 언어에는 존재하지 않음
- **function**
  - 리턴값이 있음

**nested subprogram**: 함수 안에 함수를 정의한 것  
ALGOL계열은 허용하지만 C계열을 허용하지 않음

## Parameter passing

<img src="parameter passing.png">

파라미터를 넘기는 방식에는 3가지가 있다

- **in mode**
  - 호출할 때 파라미터를 넘겨줌
- **out mode**
  - 리턴할 때 formal 파라미터를 actual 파라미터에 넣음
- **inout mode**
  - 둘 다함

out mode와 inout mode는 side effect가 발생한다.

각각의 방식을 구현하는 방법은 다음과 같다

- in mode
  - **call by value**: 함수를 호출할 때 actual 파라미터의 값을 복사해서 formal 파라미터에 넣어줌
- out mode
  - call by result: 함수가 종료될 때 formal 파라미터의 값을 복사해서 actual 파라미터에 넣어줌
- inout mode
  - call by value-result
    - call by value랑 call by result 를 합친것
    - call by copy라고도 함
  - **call by reference**
    - 파라미터의 값을 넘기는 것이 아닌 주소를 넘김
    - aliases를 생성함
  - call by name
    - 호출시가 아닌 파라미터에 접근할 때 binding됨

<img src="parameter passing implementation.png">

(w=call by value, x=call by result, y=call by value-result, z=call by reference)

주로 call by value 방식과 call by reference 방식을 사용함  
보통 out mode는 inout mode의 서브셋으로 여겨지지만 따로 분리하는 언어도 존재

call by reference 방식 사용시에 C++ 에서는 &키워드를 사용하고, C#에서는 ref, ALGOL 60에서는 var 키워드를 사용한다.

reliability를 위해 actual 파라미터의 타입과 formal 파라미터의 타입이 같은지 확인한다.  

side effect를 방지하기 위해 function의 파라미터는 in mode로 전달된다

## 기타

C/C++에서 함수를 가리키는 포인터를 선언할 수 있고 함수의 protocol이 같은 함수를 가리킬 수 있다.

오버로딩된 함수를 polymorphic subprogram, 또는 ad hoc polymorphism 이라고 한다  
파라미터의 타입을 파라미터로 받는 함수를 제네릭이라고 하고 parametric polymorphism을 이용했다.  

coroutines은 resume 키워드를 사용해서 함수 호출시 호출했던 함수에서 실행이 중단된 부분부터 실행할 수 있다
