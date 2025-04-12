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

## 중첩 서브 질의
from, where절에 select문이 중첩되어 들어갈 수 있으며, 이를 중첩 서브 질의라고 함.  

### in 연산자
in 연산자는 select절에 의해 생성된 집합의 값과 조건 집합의 값이 같은지를 판별하는 연산자이다.  
not in 도 가능
```sql
--pID가 10,21,22 중에 속하면 참
Select name, salary
from professor
where pID in (10,21,22);

--서브 질의의 결과의 cID값이 teaches 테이블의 cID 값과 같으면 그 튜플을 결과에 포함
Select distinct cID
from teaches
where semester = 'Fall' and year = 2009 and
cID in (select cID from teaches
        where semester = 'Spring' and year = 2010);

--in 연산자의 앞에 여러개의 속성이 와도 됨
Select count(sID)
from takes
where (cID,semester,year)
in (select cID, semester, year from teaches where pID=10);
```

### 비교 연산자
비교 연산자는 집합간의 비교를 위한 연산자이다.  
1. some (= any)  
   집합 중 하나라도 조건을 만족하면 참
2. all  
   모든 원소가 조건을 만족하면 참

=some 은 in 연산자와 같고, <>all 은 not in 과 같다.  

```sql
--CS학과 교수 중 적어도 한명의 임금보다 높은 임금을 받는 교수를 찾는 쿼리
Select name
from professor
where salary > some(select salary
                    from professor
                    where deptName = 'CS');

--모든 CS학과 교수보다 높은 임금을 받는 교수를 찾는 쿼리
Select name
from professor 
where salary > all(select salary
                    from professor
                    where deptName = 'CS');
```

### 상관 서브 질의
내부 중첩 질의에서 외부 테이블을 참조하면 상관 서브 질의라고 함.  
외부 테이블에서 튜플 한개를 가져와 이를 기준으로 내부 질의를 수행해야 하기 때문에 실행 시간이 오래 걸린다.  

__exists__ 키워드는 내부 질의 수행시 결과가 존재하면 참을 반환한다.  
```sql
--2009년 가을학기와 2010년 가을학기에 모두 개설된 과목을 구하는 질의
Select S.sID
from teaches as S
where S.semester = 'Fall' and S.year = 2009 and
exists(select * from teaches as T
       where T.semester = 'Fall' and T.year = 2010 and S.cID = T.cID);
```
만약 
__not exists__ 는 결과가 존재하지 않으면 참을 반환한다.  
이 키워드를 사용하여 집합 포함 관계를 나타낼 수 있다.  
A가 B를 포함한다면 
```sql
not exists(B except A)
```
위의 식은 참이다.  
이것을 이용하여 관계 대수의 나눗셈 연산을 구현할 수 있다.  
```sql
--CS 학과에서 개설한 모든 과목을 수강한 학생을 찾는 질의
Select S.sID, S.name
from student as S
where not exists(
   (select cID
    from course
    where deptName = 'CS')
   except (
      select cID
      from takes as T
      where T.sID = S.sID)
);
```

### unique 연산자
unique 구문은 서브 질의가 중복된 튜플을 가지지 않는다면 참을 반환한다.    
빈 집합(null)은 참이며 not unique도 가능하다.  
```sql
--2009년에 개설되지 않았거나 한번만 개설된 과목을 찾는 질의
Select C.cID
from course as C
where unique(
   select T.cID
   from teaches as T
   where C.cID = T.cID and T.year = 2009
);
```
튜플의 속성 중 하나라도 null이면 동일하지 않다고 판단하여 참을 반환함.  
```sql
unique(<1,2>, <1,null>) -> true
unique(<1,null>, <1,null>) -> true
```

### with 절
with 절은 임시적으로 SQL 문장의 결과를 저장하는 역할을 한다.  
with절의 범위는 with절이 있는 SQL문장에서만 유효하다.  
```sql
--예산이 가장 많은 부서를 찾는 질의
with max_budget(value) as 
   (select max(budget)
    from department)
Select deptName, budget
from department, max_budget
where department.budget = max_budget.value;
```

## from절 서브 질의
서브 질의를 from절에서도 사용 가능함.  
```sql
--평균 급여가 7000이상인 학과에 속한 교수들의 평균 급여를 구하는 질의
Select deptName, avgSalary
from (select deptName, avg(salary) as avgSalary
      from professor
      group by deptName)
where avgSalary > 7000
```
group by 절을 from 절 안으로 넣고, having 절의 역할을 where절이 대신하므로 having절을 사용할 필요가 없다.  
서브 질의의 결과를 as 연산자를 통해 재명명도 가능하다.  

기본적으로 from 절의 서브 질의는 다른 테이블을 참조하지 못한다.  
하지만 __lateral__ 절을 사용하면 서브 질의에서 from절의 다른 테이블을 참조할 수 있다.  

```sql
--교수의 이름, 급여, 소속된 학과의 평균 급여를 구하는 질의
Select P1.name, P1.salary, avgSalary
from professor as P1, lateral(
   select avg(P2.salary) as avgSalary
   from professor as P2
   where P1.deptName = P2.deptName);
```

## 스칼라 서브 질의
서브 질의가 하나의 속성을 가지는 하나의 튜플만을 반환한다면, 서브 질의가 연산식에서 값이 반환되는 어떤 곳에서도 나타날 수 있다. 이를 스칼라 서브 질의라고 한다.  
스칼라 서브 질의는 select, where, having절에서 나타날 수 있다.  
만약 스칼라 서브 질의가 여러개의 튜플을 반환한다면 런타임 에러가 발생한다.  
```sql
--모든 학과의 이름과 그 학과의 교수의 수를 구하는 질의
Select deptName, (
   select count(*)
   from professor as p1
   where d1.deptName = p1.deptName
)
from department d1;
```

출처  
데이터베이스 I 이론 및 실제, 이상호  
데이터베이스 시스템, Abraham silberschatz 외