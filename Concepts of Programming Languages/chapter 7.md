# Expressions and Assignment statements
## Arithmetic expression
연산자의 종류
- unary = 피연산자가 1개
- binary = 피연산자가 2개
- ternary = 피연산자가 3개

어떤 연산자를 먼저 계산할 것인지를 정하는 operator precedence 규칙과, 우선순위가 같은 연산자들을 어느 쪽부터 계산할 건지를 정하는 associativity 규칙을 정해햐 함

### side effect
함수 호출시 함수가 자신의 변수 이외의 변수를 바꾸는 행위를 side effect라고 함.  
call by reference 방식으로 파라미터가 넘어오거나 전역 변수를 접근하는 경우 생길 수 있음.  
이렇게 되면 변수와 그 변수를 사용하는 함수간의 결합도가 높아져 coupling이 높아지는 문제가 있다.  

함수형 언어에서는 side effect가 존재하지 않는다.  

## overloaded operator
연산자가 하나 이상의 용도로 사용되는 경우를 **operator overloading**이라고 함.  

## type conversion
type conversion은 다음 두가지로 나뉜다.  
- narrowing conversion
- widening conversion

**narrowing conversion**은 큰 타입에서 작은 타입으로 변환하는 것이고  
**widening conversion**은 작은 타입에서 큰 타입으로 변환하는 것이다.  
narrowing conversion 시에 데이터의 손실이 일어날 수 있다.  

type conversion은 다음 두가지의 방식이 있다.
- coersion
- cast

coersion은 묵시적 형변환이고, cast는 명시적 형변환이다.  

## short-circuit evaluation
단축 평가는 모든 연산을 하지 않더라고 결과가 정해지는 경우 뒤의 연산은 하지 않는 것을 의미한다.  
0으로 나누는 경우, boolean 식의 결과로 참이 나오는 경우 등에서 단축 평가가 사용된다.  
단축 평가가 수행될 경우 뒤의 식은 계산하지 않기 때문에 뒤의 식에서 배정문이 있을 경우 그 결과가 반영되지 않는다.  

## Assignment statement
배정문은 명령형 언어의 가장 중요한 문장중 하나이다.  
ALGOL60 에서는 배정문 기호로 :=를 사용하였다.  

축약된 형태의 배정문(compound assignment statement)도 존재한다  
ex) +=, *= ...

배정문의 결과는 값이 할당된 변수와 같다.  
따라서 배정문의 결과가 식의 일부로 쓰일 수 있다.  

최근 몇몇 언어들에서는 multiple assignment도 지원한다.