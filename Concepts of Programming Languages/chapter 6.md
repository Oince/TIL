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
? = 어떤 문자 하나와도 일치함
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
같은 형태의 자료를 저장하는 구조체이며 인덱스(= subscripts)를 통해 자료들을 식별한다.  
**rectangular array**는 행렬과 같이 직사각형의 형태만을 갖는 array이다.  
**jagged array**는 행의 길이가 같지 않는 array이다.  
 




