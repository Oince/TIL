# Functional Programming Languages

함수형 언어는 수학의 함수에 기반을 둔 언어  
최초의 함수형 언어로 **Lisp**가 있으며, 이후에 Scheme, Commom Lisp등의 언어가 나왔다

## 특징

- 반복문 대신 재귀 사용
- side effect가 없음
- 명령형 언어에 비해 간결한 구조를 가지고 있음
- prefix 사용

# Logic Programming Languages

Logic 언어는 fact와 rule을 기반으로 한 언어이다  
주어진 fact와 rule로 goal(query) 문장을 수행하면 참 or 거짓이 결과로 나온다  

## Prolog

Prolog는 **term**으로 이루어져 있으며 term에는 3가지 종류가 있다

- constant: 상수
  - atom(문자열)과 숫자
- variable: 변수
- structure
  - functor와 파라미터 리스트로 이루어져 있음

fact 문장은 사실을 정의하는 문장이고, fact는 functor와 파라미터로 구성되어 있다.  
 rule 문장은 사실들간의 관계를 나타내고 :- 기호를 사용한다

주어진 fact와 rule을 기반으로 goal 문장을 실행하면 추론(inferencing) 과정을 거쳐서 true/false/don't know 3가지 결과가 나온다