# Trigger
트리거는 SQL의 제약 조건으로 나타낼 수 없는 무결성 제약을 구현하기 위해 사용함  
트리거는 다음 3가지 부분으로 나뉨  
- event: 트리거가 작동하는 상황
  - (after/before) (insert/update/delete) of (컬럼명) on (테이블명)

- condition: 트리거가 작동하는 조건, **when** 구문 사용
- action: 상황과 조건이 맞으면 실행하는 문장, **begin end** 구문 사용

```sql
Create trigger credit_earned after update of grade on takes
referencing new row as nrow
referencing old row as orow
for each row
when nrow.grade <> 'F' and nrow.grade is not null 
	and (orow.grade = 'F' or orow.grade is null)
begin
	update student
	set tot_credit = tot_credit + (select credits
                                        from course
                                      	where course.course_id = nrow.course_id)
    where student.id = nrow.id;
end;                                 
```

**create trigger** 구문으로 트리거를 생성하고, 트리거 이름을 지정한 뒤 이벤트 정의가 나온다.  
이벤트 정의는 **after**, **before** 두가지가 있고, after는 이벤트가 수행된 이후에 트리거가 수행되고, before는 이벤트가 수행되기 전에 트리거가 수행된다  
이후에 트리거가 작동해야 하는 동작(insert/update/delete)이 나오고, 변경된 테이블이 나온다. 속성명은 생략 가능하다  
위의 예제에서는 takes 테이블의 grade 속성에 update연산이 발생한 이후에 이 트리거가 실행되도록 설정했다.

**referencing new row** , **referencing old row** 는 각각 새로 삽입/갱신된 튜플, 이전에 있던 삭제/갱신된 튜플을 나타낸다.  
**for each row** 는 값이 변화된 튜플을 기준으로 작업을 수행하는 것을 의미한다.  
하나의 튜플 단위가 아닌 SQL 문장 단위로 트리거를 수행하려면 **for each statement** 구문을 사용한다.  
**referencing new table**, **referencing old table**을 사용하여 영향을 받은 임시 테이블을 참조한다.

**when** 구문은 트리거의 조건을 나타낸다. 이 조건을 만족하지 못하면 트리거는 수행되지 않는다.  
위의 예제에서는 새로운 튜플의 grade가 F와 null 전부 아니어야 하고 예전 튜플의 grade가 F이거나 null일 때를 트리거의 조건을 지정했다.

**begin end** 구문은 트리거가 실행할 작업을 나타낸다.  
위의 예제에서는 학생 테이블의 tot_credit 값을 변화된 takes의 grade값을 이용해 새로 계산한다.  
**begin atomic (SQL 문장) end** 구문은 이 작업을 트랜잭션으로 처리한다는 뜻이다.
