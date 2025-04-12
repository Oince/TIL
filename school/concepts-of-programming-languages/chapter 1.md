# Preliminaries

## 평가 기준
__readability__ 는 프로그램이 읽기 쉬운지를 나타내는 기준이다.  
언어의 간단함(simplicity), 기본 기능을 조합하면서 사용 가능한지 여부(orthogonality), data type, syntax design 등이 평가 항목에 속함.  

__writability__ 는 프로그램을 작성하기가 얼마나 쉬운지를 나타내는 기준이다.  
readability 평가 항목에 더해 abstraction, expressivity 가 속함.  

__reliability__ 는 프로그래밍 언어가 얼마나 신뢰성이 있는지 나타내는 기준이다.  
readability, writability 평가 항목에 더해서, 타입 체킹, 예외 처리, alliasing 등이 속함.  

## 폰 노이만 구조
현대 컴퓨터는 __폰 노이만 구조__ 를 채택하고 있고 이 구조에서 작동하는 언어를 __명령형 언어__ 라고 한다.  
폰 노이만 구조는 메모리에서 명령어를 fetch하고, 그 명령어를 해석해서 cpu에서 실행하고 다음 명령어를 다시 fetch하는 구조를 가지고 있으며, 이를 __fetch-execute cycle__ 이라고 한다.  
__program counter(PC)__ 레지스터가 존재하여 다음 명령어의 위치를 가리킨다.  

## 언어 분류
1. imperative language
2. functional language
3. logic language

객체 지향 언어는 명령형 언어의 하위 카테고리로 여김.  

## 해석 방법
프로그래밍 언어를 해석하여 기계어로 바꾸는 방법은 3가지가 있다.
1. compilation
2. pure interpretation
3. hybrid implementation

### 컴파일
컴파일 방식은 컴파일러가 미리 기계어로 코드를 번역해놓고, 이후에 실행할 때 미리 번역된 기계어를 실행하는 방식이다.  
lexical analyzer와 syntax analyzer를 이용해서 중간 코드를 만들고, 중간 코드를 다시 기계어롤 변환하는 방식이다.  
c/c++와 같은 언어가 사용하는 방식이다.

### 인터프리터
인터프리터 방식은 일종의 가상머신인 인터프리터를 통해 코드를 바로 해석하는 방식이다.  
컴파일 방식처럼 미리 기계어로 번역한 후 실행하는 것이 아닌 인터프리터가 코드를 읽어가며 바로 실행한다.  
컴파일 방식에 비해 디버깅이 편리하고 이식성이 좋다는 장점이 있지만 속도가 느리고 더 많은 메모리를 사용한다는 단점이 있다.  
Lisp, javascript, PHP등이 사용하는 방식이다.  

### 하이브리드
하이브리드 방식은 위의 두 방법을 적절히 섞은 것으로 중간 코드를 만드는 것 까지는 컴파일 방식과 같지만 그 중간 코드를 인터프리터 방식처럼 바로 실행하는 방식이다.  
자바가 이와 같은 방식을 사용하며 jvm이 자바 바이트 코드를 실행하는 인터프리터 역할을 한다.  
컴파일 방식과 인터프리터 방식의 장점을 가져왔지만 여전히 컴파일 방식에 비해 느리기 때문에 __JIT(Just-in_time)__ 방법이 도입되었다.  
JIT는 코드가 호출될 때 컴파일하여 기계어로 변환하여 실행 후 그 결과를 저장해두어 다음에 실행할 때 컴파일한 기계어를 실행하도록 하는 방법이다.  

출처  
Concepts of programming languages, Robert W. Sebesta