# Select
Select 문장은 기본적으로 3개의 절로 나뉨  
## Select  
관계 대수의 project 연산에 대응  
질의 결과에 나타날 속성을 나열함  
distinct 키워드 사용시 중복을 제거함 (기본값은 all)  
## from  
관계 대수의 카티시안 곱에 대응  
하나 혹은 여러개의 관계가 올 수 있음  
질의를 수행하기 위해 접근해야 하는 관계를 나열함
## where  
관계 대수의 select 연산에 대응  
찾아올 튜플의 조건을 명시함  

예시
```sql
--professor 테이블에서 deptName이 CS이고 salary가 8000이상인 튜플의 name을 가져옴
Select name
from professor
where deptName = 'CS' and salary > 8000
```

## 추가적인 연산
### 조인 연산  

where 절에 조인 조건 적용  
```sql
Select name, cID
from professor, teaches
where professor.pID = teaches.pID;
```

자연 조인 (natural join 키워드 사용)  
```sql
Select name, cID
from professor natural join teaches;
```

자연 조인시 속성명이 중복될 경우 where절을 이용하거나 using을 사용해 조인속성 지정
```sql
Select name, title
from (professor natural join teaches) join cource using(cID);
```



### 재명명 연산  
as 키워드(생략 가능)으로 속성명 또는 테이블명 재명명 가능.  
```sql
--동일 테이블에서 비교 연산을 할 때 재명명 연산을 통해 가져옴
Select distinct T.name
from professor as T, professor as S
where T.salary > S.salary and deptName
```

### 문자열 연산  
작은 따옴표를 통해 문자열 표현  
% 기호는 어떤 문자열과도 일치함  
_ 기호는 어떤 문자와도 일치함  
like 연산자를 사용하여 문자열 패턴을 찾을 수 있음  
%나 _가 문자열에 포함될 경우 escape를 지정해서 탈출 문자를 지정  
```sql
--name에 da가 포함된 튜플 리턴
Select name
from professor
where name like '%da%';

--title이 100%인 튜플 리턴
Select cID
from cource
where title like '100\%' escape '\';
```

### order by 절
order by 절을 사용하여 결과 튜플이 정렬된 순서로 나타나게 함.  
기본 값은 오름차순 정렬(asc) 내림차순으로 정렬하려면 desc 키워드 사용.  
여러 속성을 지정하면 앞의 속성으로 정렬한 결과를 다시 뒤의 속성으로 정렬.  
```sql
--instructor 테이블에서 salary를 내림차순으로 정렬 후, name을 오름차순으로 정렬
select *
from instructor
order by salary desc, name;
```

### where 절
between 키워드를 사용하여 값의 구간을 나타낼 수 있음
```sql
select name
from instructor
where salary between 90000 and 10000;
```

### 집합 연산  
집합 연산은 다른 select문과 다르게 중복을 허용하지 않음.  
중복 허용시 all 키워드 사용
|연산 종류|키워드|
|-|-|
|합집합|union|
|교집합|intersect|
|차집합|except|
```sql
--합집합 연산
(Select cID from teaches
where semester = 'Fall' and year = 2009)
union 
(Select cID from teaches
where semester = 'Fall' and year = 2010)

--all을 붙이면 중복 허용
(Select cID from teaches
where semester = 'Fall' and year = 2009)
union all
(Select cID from teaches
where semester = 'Fall' and year = 2010)
```

출처  
데이터베이스 I 이론 및 실제, 이상호  
데이터베이스 시스템, Abraham silberschatz 외