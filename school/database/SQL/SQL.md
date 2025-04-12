# SQL
## SQL이란?
structured query language의 약자  
관계형 데이터베이스 모델을 위한 데이터베이스 언어  
대소문자 구분이 없고, 문장의 끝에 세미콜론 사용  
DDL, DML을 포함  

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

[무결성 제약 종류](Integrity%20Constraint.md)
 
### Create
스키마를 만드는 문장
```sql
Create table professor (
  --속성명  타입       무결성 제약
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
```sql
Drop table professor;
```

### ALTER
스키마를 수정하는 문장.  
속성 추가/제거, 무결성 제약 추가/제거를 할 수 있음.  
```sql
--professor 테이블에 char형 속성 phoneNumber 추가  
Alter table professor add phoneNumber char(11);

--professor 테이블의 salary 속성 삭제
Alter table professor drop salary;
```

## DML SQL
데이터베이스 인스턴스를 조작하는 언어.  
인스턴스 생성, 조회, 삭제, 변경 등의 기능을 지원함.  

[Select 문은 내용이 길어져서 분리](/DataBase/SQL/Select문.md)

### Insert
레코드를 입력하는 연산
```sql
--professor 테이블에 레코드 입력
Insert into professor values ('41', 'Kim', 'CS', 3000);

--특정 컬럼을 선택에서 입력 가능, 비어있는 컬럼은 자동으로 null로 채워짐
Insert into professor (pIP, name) values ('42', 'Park')
```

### Delete
레코드를 삭제하는 연산
```sql
--professor 테이블의 모든 레코드 삭제
Delete from professor;

--professor 테이블의 레코드 중에 deptName이 CS인 레코드 삭제
Delete from professor where deptName='CS';
```

### Update
레코드를 수정하는 연산
```sql
--professor 테이블의 레코드 중에 salary가 3000이상이면 salary 값을 수정
Update professor 
set salary = salary * 1.03 
where salary > 3000;
```

조건이 여러개일 경우 case 문을 사용할 수 있음  
then 이후에는 조건을 만족했을 때 반환되는 값이 나타남.  
가장 먼저 조건을 만족하는 값을 반환
```sql
Update professor 
set salary = case
               when salary <= 3000 then salary*1.05
               else salary*1.03
               end;
```

## null value
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

```sql
Select ....
where salary is null;

--not null 도 가능
Select ....
where salary is not null; 
```

출처  
데이터베이스 I 이론 및 실제, 이상호  
데이터베이스 시스템, Abraham silberschatz 외