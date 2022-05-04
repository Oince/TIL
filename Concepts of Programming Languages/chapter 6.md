# Data types

**data type**은 변수가 가질 수 있는 값과 연산을 정의한다.  

## premitive data type
다른 데이터 타입으로 표현할 수 없는 타입을 primitive data type이라고 한다.  
기본적으로 4개의 타입이 있다.  
1. numeric
   1. integer
   2. float
2. character
3. boolean 

정수를 저장하는 방법 중 COBOL등에서 사용하는 방식으로 Binary coded decimal(BCD)방식이 있다.  
일반적인 경우 정수를 저장할 때 10진수를 2진수 형태로 변환하여 저장하는데 10진수 숫자 하나를 4비트 공간에 따로 저장하는 방식이다.  
추가적인 메모리 공간을 차지하는 단점이 있지만 2진수를 10진수로 변환할 필요가 없기 때문에 입출력이 빠르다는 장점이 있다.  
```
13 -> 0.....01011
BCD 방식 -> 0001 0011 로 저장
```
character 타입은 ascii 코드를 사용했으나 표현해야 할 문자가 많아지자 16bit인 unicode가 등장함.  

## Character String type
문자열 타입. 할당, 연결, 서브 스트링, 비교, 패턴 매칭 등의 연산을 지원  
패턴 매칭 방법으로 정규 표현식(regular expressions)을 사용할 수 있음.  
정규 표현식은 문자열의 패턴을 표현하는 방법.  
```
[A-Za-z] = 문자
\d = 숫자
+ = 하나 또는 여러개가 올 수 있음.
* = 어떤 문자열과도 일치함
? = 어떤 문자와도 일치함
```

### 문자열 길이
1. static 
2. limited dynamic
3. dynamic

**static length** 문자열은 정해진 길이의 문자열만 허용한다.  
**limited dynamic length** 문자열은 최대 길이를 정하고, 그 이하의 길이를 허용한다.  
**dynamic length** 문자열은 최대 길이가 없는 문자열이다.  
static 과 limited dynamic 문자열은 컴파일러가 사전에 문자열의 길이를 알 수 있지만 dynamic 문자열은 알 수 없다.  
dynamic length 문자열의 길이를 늘리는 방법은
1. 연결 리스트를 사용
2. 포인터의 배열 사용
3. 더 큰 새로운 공간으로 옮김
 
등이 있다

## Enumeration type
Enumeration 타입은 변수가 가질 수 있는 값을 나열하여 값을 제한하는 타입이다.  
일반적으로 0부터 시작하는 정수로 할당된다.  
readablilty와 reliability가 좋아진다는 장점이 있다.  

## Array type
같은 형태의 자료를 저장하는 타입이며 인덱스(= subscripts)를 통해 자료들을 식별한다.  
**rectangular array**는 행렬과 같이 직사각형의 형태만을 갖는 array이다.  
**jagged array**는 행의 길이가 같지 않는 array이다.  

## Associative array
array와 같이 같은 형태의 자료를 저장하지만 **key**를 이용해서 자료에 접근한다.  
자료를 key와 value의 쌍으로 저장한다.   
검색이 요구될 때, 자료가 쌍으로 저장될 때 유용하다.  

## record type
record 타입은 다른 종류의 자료들을 모아서 저장하는 타입이다.  
COBOL에서 처음 소개되었으며 자료에 접근할 때 **field** 이름으로 접근한다.  
대부분의 언어에서 dot notation을 사용하여 필드에 접근한다.  
**fully qualified reference**는 중간 필드명을 전부 적는 것이고  
**elliptical reference**는 결과가 모호하지 않다면 중간 필드명을 생략하는 것이다.  

## tuple type
record 타입과 비슷하게 서로 다른 자료형을 저장하지만 자료에 대한 접근은 array과 같이 인덱스를 통해 접근한다.  

## List type
list 타입은 처음에 함수형 언어에서 사용하던 타입이었으나 명령형 언어에서도 사용함.  

## Union type
union 타입은 같은 저장 공간을 여러개의 자료형이 저장될 수 있는 타입.  
각각의 필드가 서로 배타적일 때 사용함.  
c/c++에서는 형변환이 자유롭기 때문에 free union 이라고 하고 
discriminant라는 태그를 붙여서 형변환을 하는 것을 discriminanted union이라고 한다.  

## Pointer type
**pointer** 타입은 변수가 저장되어 있는 메모리의 주소를 저장하는 타입이다.  
유효하지 않은 주소를 참조할 때 **nii**이라는 값을 참조한다.  

포인터 타입의 목적은 두가지 이다.
1. indirect addressing
2. heap-dynamic 저장공간 관리 

c에서의 malloc, 객체 지향 언어에서의 new 키워드가 heap-dynamic 변수를 할당한다.  

포인터의 문제점은 
1. dangling pointer
2. lost heap-dynaimc variable (garbage)

**dangling pointer**는 이미 할당이 해제된 변수를 참조하고 있는 포인터 변수를 말한다.  
같은 heap-dynamic 변수를 참조하고 있는 두 개의 포인터 변수가 있을 때 하나의 포인터 변수만 할당을 해제할 경우 생길 수 있다.   
dangling pointer는 잘못된 위치에서 잘못된 연산을 수행할 수 있기 때문에 garbage보다 더 위험하다  

이 문제를 해결하기 위해 **tombstone** 방법이 있다.  
tombstone은 포인터가 직접 heap-dynaimc 변수를 가리키는 것이 아닌 그 둘 사이에 tombstone이라는 것을 놓아서 포인터 변수가 tombstone을 가리키게 하고 메모리 할당을 해제할 때 tombstone을 nil로 바꾸는 방법이다.  

**lost heap-dynaimc variable**은 **garbage**라고도 하며 heap-dynaimc variable을 참조하는 포인터가 없는 것을 말한다.  
이는 사용할 수 없는 변수이기 때문에 메모리의 누수를 야기한다.  

이를 해결하기 위해 **reference counter**를 사용한다.  
변수에 현재 이 변수를 참조하고 있는 포인터 변수의 개수를 저장하고, 그 개수가 0이 되면 메모리 할당을 해제하는 방식이다.  
eager 방식은 counter가 0이 되자 마자 회수하는 방식이고, 
lazy 방식은 counter가 0이 되도 기다렸다가 메모리가 부족할 때 한번에 회수하는 방식이다.  

## Type checking
타입 체킹은 연산자가 맞는지, 피연산자가 묵시적 형변환을 통해 맞는 타입으로 변하는지를 체크하는 것이다.  
이때 묵시적 형변환은 **coercion**이라고 한다.  
반대로 명시적 형변환은 **cast**라고 한다.  

**strong type**언어는 계산시 타입이 다르면 에러가 발생하는 언어이고, 
**weak type**언어는 계산시 타입이 달라도 coercion을 통해 계산하는 언어이다.  
c/c++ 는 weak type언어에 속하고 java,C#등은 strong type 언어에 속한다.  

**name type equivalence**는 타입의 이름이 같으면 같은 타입으로 여기는 것이고,  
**structure type equivalence**는 타입의 이름이 달라도 구조가 같으면 같은 타입으로 여기는 것이다.  