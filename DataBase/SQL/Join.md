# Join
두 개 이상의 테이블을 특정 조건으로 합치는 것.  
카티션 곱의 결과에 조건을 적용하는 것과 동일.  
join 키워드 사용  

## 조인 조건
1. natural
2. on
3. using

### natural
자연 조인은 두 테이블의 공통 속성으로 조인하는 것.  
공통 속성은 결과 테이블에 하나만 나옴.  
natural 키워드 사용
```sql
Select name, course_id
from student natural join takes;
```

### using
공통 속성으로 조인하는 것이 아니라, using에 나온 속성으로 자연 조인을 함.  

주로 테이블 간의 속성 이름 중에 여러개가 중복되어 원하는 속성으로 자연 조인을 하고 싶을 때 조인 속성을 명시하는 용도로 사용
```sql
Select name, title
from (student natural join takes) join course using (course_id);
```
두 테이블에 dept_name, course_id 가 둘 다 존재하므로 course_id로 조인하기위해 using 사용

### on
on 키워드는 조인 연산을 할 때 on 조건에 따라 조인 연산을 수행.  
where 절로 조건을 적용하는 것과 동일한 결과.   
```sql
Select *
from student join takes on student.ID = takes.ID;
```
자연 조인이 아니므로 결과 테이블에 student.ID, takes.ID 둘다 나옴.  

## 외부 조인
외부 조인은 조인 연산에서 값이 매치되지 않아 손실되는 정보를 유지하려고 하는 연산이다.  
조인 연산 수행 후, 제외된 튜플의 비어있는 속성을 null로 채우고 결과에 포함시킨다.  
위와 달리 튜플을 보존하지 않는 조인은 inner join 이라고 하며 inner join이 기본값이므로 inner 키워드는 생략한다.  

외부 조인에는 3가지 종류가 있다.  
1. left outer join  
조인 연산의 왼쪽에 있는 테이블의 튜플만 보존
2. right outer join  
조인 연산의 오른쪽에 있는 테이블의 튜플만 보존
3. full outer join  
모든 테이블의 튜플 보존  

```sql
--왼쪽 외부 조인
Select * 
from student natural left outer join takes;

--오른쪽 외부 조인 
Select *
from student natural right outer join takes;

--전체 외부 조인
Select * 
from student natural full outer join takes;
```



