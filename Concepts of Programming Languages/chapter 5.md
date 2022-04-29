# Chapter 5
변수의 특성에 대해서 다룬다.  
## 변수란?
변수는 메모리 셀 또는 셀의 모음을 추상화한 것.  
변수는 6가지의 특성을 가지고 있음

## 변수의 기본 특성
### 1. Name
변수를 특정하기 위한 문자열  
대부분의 언어에서 영어 대소문자, 숫자, _ 로 구성  
영어 대소문자를 구분함(case sensitive)  
미리 정해져서 변수 이름으로 사용이 불가능한 예약어(reserved word = keyword)가 있음  
예약어는 문법을 구분하기 위해 미리 정해놓은 단어.  

### 2. Address
변수와 연관된 메모리의 주소  
변수가 배정문의 왼쪽에 있을 때 주소로 여겨지기 때문에 l-value 라고도 부름  

#### Alias
같은 주소를 가지는 다른 변수를 alias 라고 함.  
alias의 종류  
1. union  
   c/c++ 에서의 union 타입
2. pointer
3. parameter(call by reference일 경우)  
   1. formal parameter - 함수 선언문에 있는 파라미터  
   2. actual parameter - 함수를 호출할 때 넘겨주는 파라미터  

### 3. Value
메모리에 저장되어 있는 내용  
변수가 배정문의 오른쪽에 있을 때 그 변수의 값으로 여기지기 때문에 r-value라고도 함.  

### 4. type 
6장에서 자세히 다룸

## Binding
바인딩은 변수와 그 변수의 속성을 결합하는 것.  
속성에는 타입, 값 등이 있음

바인딩에는 static 과 dynamic 방식이 있음  
static은 실행 전(컴파일 타임)에 바인딩되고 실행 후에 변하지 않는 것을 뜻함.  
dynamic은 실행 후(런타임)에 바인딩 되고 이후에 바뀔 수 있음을 뜻함.  
|종류|실행 시점|값의 변화|
|-|-|-|
|static|실행 전(= 컴파일 타임)|불가능|
|dynamic|실행 후(= 런타임)|가능|

## Type binding
### static type binding
static type binding에는 명시적으로 타입을 선언하는 explicit declaration과 암시적으로 타입을 바인딩하는 implicit declaration이 있다.  
implicit declaration는 명시적인 선언 없이 암시적으로 변수의 타입을 결정하는 방식이다.  
ex)포트란과 같은 언어에서 i-n까지의 문자가 변수명의 앞글자이면 정수, 이외에는 실수로 정의되는 방식이다.  

대부분의 언어는 explicit declaration을 사용한다.  
변수의 타입을 명시적으로 선언하여 타입을 정하는 방식이다.  

### dynamic type binding
dynamic type binding은 타입을 미리 정해놓는 것이 아닌 실행중에 타입이 결정되도록 하는 방법이다.  
배정문에 의해 변수에 값이 할당될 때 타입이 결정된다.  
인터프리터 언어에서 주로 사용된다.  
단점으로는 타입 체킹이 없어서 프로그램이 덜 신뢰적이게 되고, 런타임에 정해지므로 미리 정해놓는 static type binding에 비해 성능이 좋지 않다.  

## 메모리 구조
변수의 lifetime은 메모리의 어느 위치에 저장되는지에 따라서 달라지므로 기본적인 메모리 구조에 대해서 알아야한다.  

메모리 구조는 code(instruction)영역, data영역, stack영역, heap영역으로 나뉜다.  

### code 영역
실행할 프로그램의 기계어 코드가 저장되어 있는 공간

### data 영역
전역 변수, static 변수 등이 할당되는 공간

### stack 영역
stack의 형식으로(FILO) 저장  
지역 변수가 할당되는 공간

### heap 영역
사용자가 할당한 변수(malloc, new 등)이 할당되는 공간

## storage binding & lifetime
### static variable
프로그램이 시작할 때 등록되고, 프로그램이 실행중일 때 계속 남아있다가 프로그램이 종료될 때 해제되는 변수.  
전역 변수가 해당되며, data영역에 저장된다.  
history sensitive한 특성이 필요할 경우 지역 변수를 static하게 할당할 수 있다. ex)c/c++ static 키워드  

### stack-dynamic variable
해당 변수가 있는 부분이 실행될 때, stack영역에 저장되고 실행이 끝나면 삭제됨.  
지역 변수가 해당됨.  

### heap-dynamic variable
프로그래머에 의해 실행시에 메모리에 할당되는 변수.  
heap영역에 할당되며, 포인터나 참조 변수로만 해당 변수에 접근할 수 있음  
메모리 할당을 해제하면 메모리에서 삭제됨.  
c의 malloc, c++의 new 연산자 등이 heap-dynamic 변수를 만드는 역할을 하고 c의 free(), c++의 delete 등이 할당을 해제하는 역할을 함. 

## scope
변수가 참조되거나 배정될 수 있는 범위를 scope라고 한다.















출처  
Concepts of programming languages, Robert W. Sebesta