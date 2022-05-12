# 무결성 제약
## 무결성 제약이란?
무결성 제약은 데이터가 항상 만족해야 하는 조건이다.  
테이블의 속성에 적용 가능하다.  
다음과 같은 무결성 제약이 있다.  
- not null
- unique
- check
- primary key
- 참조 무결성 제약

## not null
not null 제약 조건은 해당 데이터에 null을 허용하지 않는다는 조건이다.  
```sql
--name은 null이 될 수 없음
name varchar(20) not null
```

## unique
unique 제약 조건은 해당 속성이 중복된 값을 가질 수 없게 하는 조건이다.  
super key를 구성하는 것과 같다.  
not null을 선언하지 않는 한 null값을 가질 수 있다.  
```sql
--A1, A2, ... 의 조합은 중복되지 않음
unique(A1, A2, ...)
```

## check
check 제약 조건은 check 조건을 만족하게 하는 조건이다.  
```sql
--semester는 4가지 값 중에 하나여야 함
semester varchar(20) check(semester in ('Fall', 'Winter', 'Spring', 'Summer'))

--budget은 0보다 커야 함
budget numeric(12,2) check (budget > 0) 
```

## primary key
primary key 제약 조건은 지정 속성이 다른 모든 튜플의 속성과 같지 않게 하는 속성이다.  
null을 허용하지 않는다는 점이 unique와 다르다
```sql
primary key(A1, A2, ...)
```

## 참조 무결성 제약
참조 무결성 제약은 참조하는 속성이 참조되는 테이블에 나타나야 하는 제약 조건이다.  
**외래 키(foreign key)** 는 참조하는 속성이 참조되는 테이블의 주 키를 참조하는 것이다.  
```sql
--dept_name 속성이 department 테이블의 주 키를 참조함
foreign key (dept_name) references department
```

외래 키는 null을 가질 수 있지만 외래키가 참조하는 속성은 primary key 이므로 null이 될 수 없다.  

**on delete/update cascade** 구문을 사용하면 참조되는 테이블의 값이 변동이 있을 경우 그 테이블을 참조하는 테이블에 연속적으로 값이 변하게 된다.  
```sql
foreign key (dept_name) references department
            on delete cascade
            on update cascade
```
위와 같이 설정하면 department 테이블의 튜플이 삭제/변경될 때 그 튜플을 참조하고 있는 다른 테이블의 튜플도 삭제/변경된다.  
cascade 대신에 **set null** 을 사용할 경우에는 참조하고 있는 튜플의 값이 null로 설정되고, **set default**를 사용할 경우에는 값이 도메인의 기본 값으로 설정된다.  

참조하는 테이블에 먼저 데이터를 넣을 경우 참조 무결성 제약에 의해서 데이터 삽입이 거절된다.  
이런 상황을 해결하기 위해 SQL은 무결성 제약을 잠시 연기시킬 수 있는 **deferred** 키워드를 제공한다.  
트랜잭션에서 다음과 같은 명령어를 사용하면 무결성 제약을 트랜잭션의 마지막으로 연기시킨다.  
```sql
set constraints <무결성 제약 이름> deferred
```
 
## 복잡한 무결성 제약
check 절의 조건에 하위 질의를 사용할 수 있다.
```sql
check (time_slot_id in (select time_slot_id from time_slot))
```

**assertion(주장)** 은 데이터베이스가 항상 만족해야 하는 조건을 표현하는 술어이다.  
**Create assertion** 문장으로 생성한다.
```sql
Create assertion credits_earned_constraint check (
    not exists (
        select ID
        from student
        where tot_cred <> ( select coalesce(sum(credit), 0)
                            from takes natural join course
                            where student.ID = takes.ID 
                              and grade is not null and grade <> 'F'
        )
    )
)
```
위의 두 방법을 유지시키는데 많은 비용이 들어가기 때문에 대부분의 DBMS에서는 이 방법들을 지원하지 않는다.  
