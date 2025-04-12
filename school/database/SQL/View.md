# View
## View란
특정 사용자로부터 특정 데이터를 숨기는 기능.

## View 정의
```sql
Create view <view 이름> as <query 문장>
```
**Create view** 명령어로 생성.  
as 뒤에 sql 질의문의 결과에 해당하는 테이블이 view가 됨.  

예시
```sql
--instructor 테이블에서 ID, name, dept_name 가져온 결과를 faculty 뷰로 정의
Create view faculty as
    select ID, name, dept_name
    from instructor;
```
view를 virtual relation, view를 정의할 때 사용한 실제 tuple을 가지는 릴레이션을 base relation이라고 함.  

view를 정의할 때 다른 view를 이용해서 정의할 수도 있음.  

view는 질의 결과의 튜플을 저장하는 것이 아님.  
대신 DBMS가 질의 표현식 자체를 저장하여, view에 접근할 때 마다 질의를 계산하여 튜플을 생성함.   

## View 갱신
view의 갱신(insert, update, delete) 연산은 많은 제약이 있음.  

다음 조건을 모두 만족하면 **갱신가능(updatable)** 이라고 함.  
- from 절은 하나의 테이블만 가져야 한다.
- select 절은 테이블의 속성 이름만 포함해야 한다.
  - 표현식, 집계 함수, distinct 키워드 불가능
- select 절에 나오지 않은 속성은 null을 허용해야 한다.
- group by 절이나 having 절을 가지면 안된다.

위의 조건을 만족해서 updatable해도 연산의 결과가 view에 반영되지 않는 경우가 있음.  
이때 **with check option** 을 사용하면 연산시 where절 조건을 만족하지 않을 때는 연산을 허용하지 않음.  

## View 제약
- view에 대한 index는 불가능
- 무결성 제약 설정 불가
