# Lexical and Syntax Analyzer
## Lexical analysis
Lexical analyzer는 syntax analyzer의 front-end와 같다.  
Lexical analyzer는 입력으로 프로그램을 받고, 문자 하나씩을 검사해서 lexemes과 token을 찾아 syntax analyzer에게 전달한다.  
lexemes을 찾을 때 공백이나 주석은 무시하며 identifier를 symbol table에 등록한다.  
state transition diagram을 이용하여 만들고 구현은 재귀함수를 이용한다.  

## syntax analyzer
syntax analyzer는 인풋으로 들어온 프로그램이 문법적으로 맞는지 체크하며, parse tree를 생성하는 역할을 한다.  
syntax analysis는 parsing이라고도 하며, parsing 방식에는 두가지 방식이 있다.  
1. top-down parsing
2. bottom-up parsing

### Top-down parsing
__top-down__ 방식은 start symbol 에서부터 시작해 문장을 만들어 내는 방식이며, LL 알고리즘이라고도 불린다.  
LL의 의미는 인풋을 왼쪽부터 스캔하고, leftmost derivation한다는 뜻이다.  
가장 널리 알려진 top-down 알고리즘은 __recursive-descent parser__ 이다.  
nonterminal을 함수로 만들고, 재귀함수를 이용하여 구현한다.  

### Bottom-up parsing
__bottom-up__ 방식은 문장을 조합하면서 start symbol로 만들면서 분석하는 방법이며, LR 파싱이라고도 불린다.  
이 방식은 상태와 요소를 저장하는 스택과 두 개의 테이블로 파싱한다.  
**Action** 테이블은 상태 또는 룰이 적혀있고 상태 변화시 스택에 해당하는 nonterminal과 그 상태를 스택에 넣는다.  

룰을 적용할 때는 스택에서 nonterminal을 꺼내 reduce하고 해당하는 상태의 **goto**테이블에서 terminal을 찾아 스택에 넣는다.  
