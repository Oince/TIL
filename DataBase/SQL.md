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
2. varchar(n) : 길이가 1 ~ n인 문자열
3. int : 정수
4. numeric(p,d) : p는 숫자 개수, d는 소수점 개수  
   ex) numeric(5,2) = 123.45

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

### Insert
레코드를 입력하는 연산
```
//professor 테이블에 레코드 입력
Insert into professor values ('41', 'Kim', 'CS', 3000);

//특정 컬럼을 선택에서 입력 가능, 비어있는 컬럼은 자동으로 null로 채워짐
Insert into professor (pIP, name) values ('42', 'Park')
```

### Select

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











