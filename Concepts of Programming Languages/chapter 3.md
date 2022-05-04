# Describing syntax and semantics

## syntax & semantic
syntax는 그 언어의 형태이고 semantic은 언어의 의미이다.  
언어의 문장은 sentense 라고 하고, 그 문장의 단어들을 lexemes 라고 한다.  
token은 lexem의 카테고리(품사)이다.  

## Context-free Grammars
자연어와 같이 단어 하나가 맥락에 따라 여러개의 의미를 갖는 언어를 Context-sensitive 언어 라고 한다.  
프로그래밍 언어는 자연어와는 달리 단어 하나가 명확하게 하나의 의미 만을 가져야 한다.  
위와 같은 언어를 Context-free 언어 라고 한다.  

## Backus-Naur Form
BNF는 언어의 syntax를 묘사하기 위한 메타 언어이다.  
메타 언어는 다른 언어를 설명하는 언어이다.  
BNF에는 3가지 표기법이 있다
1. ->
2. <>
3. |

__->__ 기호는 언어의 룰을 나타내는 기호이다.  
화살표 왼쪽에 있는 것은 LHS라고 하고, 오른쪽에 있는 것은 RHS라고 한다.  
LHS에는 nonterminal만 올 수 있으며, RHS에는 nonterminal과 terminal 모두 올 수 있다.  
__grammar__ 는 룰의 집합을 의미한다.  

__<>__ 기호는 nontermianl을 표기하기 위한 기호이다.  
__nonterminal__ 은 어휘(lexem, token)등이 아닌 것을 의미하며, 반드시 <>기호 안에 있어야 한다.  
__terminal__ 은 어휘를 의미하며, 문장은 terminal로만 이루어져 있다.  

__|__ 기호는 하나의 nonterminal에 대한 여러개의 룰을 한 번에 표시할 수 있게 하는 기호이다.  

BNF는 LHS의 nonterminal이 RHS에 나오는 것을 허용하며, 이를 재귀적인 룰이라고 한다.  

맨 처음에 나오는 nonterminal을 __start symbol__ 이라고 하며, LHS에 있는 nonterminal을 오른쪽으로 바꾸는 것은 __derivation__ 이라고 한다.  
derivation 과정에서 왼쪽에 있는 nonterminal부터 derivation하는 것을 leftmost derivation이라고 하고 오른쪽에 있는 것을 먼저 할 경우 rightmost derivation이라고 한다.  
derivation 과정 중 nonterminal이 포함된 중간 문장을 sentential form 이라고 한다.  

예시
```
<program> -> begin <stmt_list> end
<stmt_list> -> <stmt>
             | <stmt> ; <stmt_list>
<stmt> -> <var> = <expression>
<var> -> A | B | C
<expression> -> <var> + <var>
              | <var> - <var>
              | <Var>
```
위의 예제에서 룰은 5개(엄밀히 6개), nonterminal은 5개, terminal은 9개(begin, end, ;, =, A, B, C, +, -), start symbol은 \<program\> 이다. 


deriation 과정을 트리로 나타낸 것을 __parse tree__ 라고 함. 
parse tree의 리프 노드에는 항상 terminal만 있음.  

parse tree가 두개 이상 존재하는 grammar는 모호하다고 함.  
모호한 문법을 해결하는 방법은 우선 순위를 지정하고, 우선 순위가 같을 경우 어떤 것 부터 계산할건지를 정하는 결합 법칙을 정해주어야 한다.  
우선 순위가 높은 룰을 밑에 정의하여 우선순위를 지정한다.  
결합 법칙은 RHS의 왼쪽에 나온 것을 먼저 계산할 경우(좌결합) 재귀가 왼쪽에 나오고, 오른쪽 먼저 계산할 경우(우결합) 오른쪽에 나오도록 한다.  

## Extended BNF
EBNF는 BNF를 좀 더 편하게 사용하기 위해 만들어졌고, 더 확장된 표기법을 제공한다.  
EBNF의 표기법 중 가장 일반적인 3개는 다음과 같다.
1. []
2. {}
3. ()

[] 기호 안예 있는 표현은 안나오거나 한번만 나올 수 있다.  
{} 기호 안예 있는 표현은 안나오거나 여러먼 나올 수 있다.  
() 기호 안에 있는 표현은 그 안에 있는 표현들 중 하나를 선택한다.  