#  Statement Level Control Structures

**Control statement**는 PC값을 변화시키는 문장이다.  
두 가지 종류가 있다.

- Selection statement
- iteration statement

## Selection statement

- two-way selection
  - if-else문장
- multiple selection
  - switch 문장

## Iterative statement

loop 라고도 함

- Counter-controlled loop
  - for 문장
  
- Logically controlled loop
  - while, do-while 문장
- Iteration based on data structure
  - 자료 구조에 대한 반복
  - C#에서는 `foreach`구문으로 사용한다


## Unconditional branch statement

execution control을 프로그램의 특정 위치로 이동시키는 문장  
**goto** 문장이 그 예시이며 몇몇의 언어에서는 지원하지 않지만 C언어에서는 지원함  
wild goto 문은 아무데로나 갈 수 있고, structured goto문은 break, continue 처럼 특정 위치로만 이동할 수 있는 문장임.

