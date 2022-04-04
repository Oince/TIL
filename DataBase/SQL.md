# SQL
## SQL이란?
structured query language의 약자  
관계형 데이터베이스 모델을 위한 데이터베이스 언어  
대소문자 구분이 없고, 문장의 끝에 세미콜론 사용  
DDL, DML, DCL을 모두 포함  

## DDL SQL
데이터베이스 스키마를 정의하는 언어.  
스키마 생성, 스키마 삭제, 스키마 변경 등의 작업을 수행함.  

### SQL domain type
데이터 타입  
1. char(n) : 길이가 n인 문자열  
   길이가 n 이하일 경우 나머지를 공백으로 채움  
2. varchar(n) : 길이가 최대 n인 문자열
3. int : 정수
4. numeric(p,d) : p는 숫자 개수, d는 소수점 개수  
   ex) numeric(5,2) = 123.45   

이외에도 다양한 내장 타입이 있음  

### 무결성 제약 종류
1. primary key(속성1, 속성2, ...)  
   괄호 안에 들어간 속성이 주 키임을 나타냄  
   주 키 속성은 null을 가질 수 없으며 다른 튜플과 중복될 수 없음  
2. foreign key(속성1, 속성2, ...) references s  
   괄호안에 들어간 속성이 s가 가지고 있는 주 키 속성과 일치함을 나타냄  
3. not null  
   null값을 허용하지 않음  


### Create
스키마를 만드는 문장
```
Create table professor (
  //속성명  타입       무결성 제약
    pID     char(5),
    name    varchar(20) not null,
    deptName varchar(20),
    salary  numeric(4, 0),
    //무결성 제약
    primary key (pID),
    foreign key (deptName) references department
);
```


### Drop
스키마를 삭제하는 문장.  
인스턴스까지 전부 삭제함.  
```
Drop table professor;
```

### ALTER
스키마를 수정하는 문장.  
속성 추가/제거, 무결성 제약 추가/제거를 할 수 있음.  
```
//professor 테이블에 char형 속성 phoneNumber 추가  
Alter table professor add phoneNumber char(11);

//professor 테이블의 salary 속성 삭제
Alter table professor drop salary;
```

## DML SQL
데이터베이스 인스턴스를 조작하는 언어.  
인스턴스 생성, 조회, 삭제, 변경 등의 기능을 지원함.  

### Select
Select 문장은 6개의 절로 나뉨  
1. Select  
   관계 대수의 project 연산에 대응  
   질의 결과에 나타날 속성을 나열함  
   distinct 키워드 사용시 중복을 제거함 (기본값은 all)  
2. from  
   관계 대수의 카티시안 곱에 대응  
   하나 혹은 여러개의 관계가 올 수 있음  
   질의를 수행하기 위해 접근해야 하는 관계를 나열함
3. where  
   관계 대수의 select 연산에 대응  
   찾아올 튜플의 조건을 명시함  
   between 키워드 사용하여 값의 구간을 나타낼 수 있음
4. group by
5. having
6. order by
   결과 튜플을 정렬하는데 사용
   기본값은 오름차순(asc), 내림차순으로 변경은 속성 뒤에 desc 키워드 추가  
   

```
//professor 테이블에서 deptName이 CS이고 salary가 8000이상인 튜플의 name을 가져옴, name을 기준으로 오름차순으로 정렬
Select name
from professor
where deptName = 'CS' and salary > 8000
order by name;
```

#### 작동 순서 
1. from 테이블에서 튜플을 하나씩 들고옴
2. where 절 조건 적용  
   2-1 참이면 group by절로 이동  
   2-2 거짓이면 결과 테이블에서 제외  
3. group by 속성을 이용하여 서브그룹으로 나눔
4. having 절 조건을 이용하여 참인 서브그룹 선택
5. order by 절 조건을 적용하여 결과 테이블로 내보냄

#### 추가적인 연산
조인 연산
```
//조인 연산, where 절에 조인 조건 적용
Select name, cID
from professor, teaches
where professor.pID = teaches.pID;

//자연 조인 (natural join 키워드 사용)
Select name, cID
from professor natural join teaches;

//자연 조인시 속성명이 중복될 경우 where절을 이용하거나 using을 사용해 조인속성 지정
Select name, title
from (professor natural join teaches) join cource using(cID);
```

재명명 연산  
as 키워드(생략 가능)으로 속성명 또는 테이블명 재명명 가능.  
```
//동일 테이블에서 비교 연산을 할 때 재명명 연산을 통해 가져옴
Select distinct T.name
from professor as T, professor as S
where T.salary > S.salary and deptName
```

문자열 연산  
작은 따옴표를 통해 문자열 표현  
% 기호는 어떤 문자열과도 일치함  
_ 기호는 어떤 문자와도 일치함  
%나 _가 문자열에 포함될 경우 escape를 지정해서 탈출 문자를 지정
```
//name에 da가 포함된 튜플 리턴
Select name
from professor
where name like '%da%';

//title이 100%인 튜플 리턴
Select cID
from cource
where title like '100\%' escape '\';
```

집합 연산  
집합 연산은 다른 select문과 다르게 중복을 허용하지 않음.  
중복 허용시 all 키워드 사용
|연산 종류|키워드|
|-|-|
|합집합|union|
|교집합|intersect|
|차집합|except|
```
//합집합 연산
(Select cID from teaches
where semester = 'Fall' and year = 2009)
union 
(Select cID from teaches
where semester = 'Fall' and year = 2010)

//all을 붙이면 중복 허용
(Select cID from teaches
where semester = 'Fall' and year = 2009)
union all
(Select cID from teaches
where semester = 'Fall' and year = 2010)
```

#### null value
연산시 null이 있으면 특별한 처리가 필요함.  
입력 값이 null일 때  
  
산술 연산식의 결과는 null  
ex) 5 + null = null  
  
비교 연산식의 결과는 unknown  
ex) 5 > null = unknown  
  
unknown이 들어간 논리 연산의 결과는  
true and unknown = true  
false or unknown = false  
이외의 나머지는 전부 unknown임.  

where절은 조건이 true인 것만 결과에 포함(false, unknown 제외)  

null인 값을 찾을 때는 is null 사용

```
Select ....
where salary is null;

//not null 도 가능
Select ....
where salary is not null; 
```

### Insert
레코드를 입력하는 연산
```
//professor 테이블에 레코드 입력
Insert into professor values ('41', 'Kim', 'CS', 3000);

//특정 컬럼을 선택에서 입력 가능, 비어있는 컬럼은 자동으로 null로 채워짐
Insert into professor (pIP, name) values ('42', 'Park')
```

### Delete
레코드를 삭제하는 연산
```
//professor 테이블의 모든 레코드 삭제
Delete from professor;

//professor 테이블의 레코드 중에 deptName이 CS인 레코드 삭제
Delete from professor where deptName='CS';
```

### Update
레코드를 수정하는 연산
```
//professor 테이블의 레코드 중에 salary가 3000이상이면 salary 값을 수정
Update professor set salary = salary * 1.03 where salary > 3000;
```

출처  
데이터베이스 I 이론 및 실제, 이상호  
데이터베이스 시스템, Abraham silberschatz 외