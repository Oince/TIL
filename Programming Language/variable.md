# 변수
## 변수란?
변수는 메모리 셀 또는 셀의 모음을 추상화한 것.  
변수는 6가지의 특성을 가지고 있음

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

### Type binding
#### static type binding  


### 4. lifetime

### 5. scope

### 6. type













출처  
Concepts of programming languages, Robert W. Sebesta