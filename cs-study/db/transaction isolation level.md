# Transaction isolation level

트랜잭션의 격리 수준은 여러 트랜잭션이 동시에 처리될 때 트랜잭션간 고립되어 있는 정도를 의미한다. 즉 한 트랜잭션에서 다른 트랜잭션이 변경한 데이터에 접근이 가능한지 여부를 결정하는 것이다.

격리 수준은 4가지가 있으며, 밑으로 갈수록 격리 수준이 높아진다.

- read uncommitted
- read committed
- repeatable read
- serializable

모든 격리 수준은 dirty write를 허용하지 않는다. 즉 한 트랜잭션이 write한 데이터는 커밋되기 전에 다른 트랜잭션에서 접근이 불가능하다. 위의 격리 수준은 오직 read 연산에 대한 격리 수준만이 차이가 있다.

## read uncommitted

read uncommitted 수준에서는 다른 트랜잭션의 변경 내용이 커밋되기 전에 데이터에 접근할 수 있다. 커밋되지 않은 데이터를 읽을 수 있기 때문에 dirty read 현상이 발생한다. dirty read는 트랜잭션이 커밋되기 전에 데이터에 접근하여 read한 경우를 말한다.

- x = 50
- A 트랜잭션에서 x = 100으로 변경
- B 트랜잭션에서 read (x = 100)
  - dirty read 발생
- A 롤백
- B 트랜잭션은 롤백되기 전의 잘못된 값(x = 100)을 가지고 있음

## read committed

read committed는 커밋된 데이터만 read할 수 있는 수준이다. read uncommitted는 non-repeatable read가 발생할 수 있다. non-repeatable read는 하나의 트랜잭션에서 동일한 select문을 실행했을 때 같은 결과가 나와야 한다는 repeatable read를 위반하는 것이다.

- A 트랜잭션에서 x 조회 (x = 50)
- B 트랜잭션에서 x = 100 으로 변경 후 커밋
- A 트랜잭션에서 x 다시 조회 (x = 100)
  - non-repeatable read 발생

## repeatable read

repeatable read는 read committed에서 non-repeatable read를 해결한 격리 수준이다. 이 수준은 트랜잭션이 시작되기 전에 커밋된 내용에 대해서만 read 할 수 있다. repeatable read는 phantom read 현상이 발생할 수 있다. 이는 동일한 read 연산에 대해 검색되는 레코드의 수가 달라질 수 있는 현상이다. 데이터의 값이 변하는 것이 아닌 새로운 레코드가 보이거나, 보이지 않게 되는 현상을 말한다.

- A 트랜잭션에서 member 테이블 read
  - id:1, name: alice
  - id:2, name: bob
- B 트랜잭션에서 member 테이블에 insert
  - id:3, name: charlie
- A 트랜잭션에서 member 테이블 다시 read
  - id:1, name: alice
  - id:2, name: bob
  - id:3, name: charlie
    - phantom read 발생

## serializable

serializable은 항상 직렬 가능한 실행을 보장하는 수준이다. 모든 read 연산에 lock을 걸기 때문에 위에서 나온 dirty read, non-repeatable read, phantom read 현상이 발생하지 않는다. 데이터의 일관성이 높지만 동시 처리 능력이 떨어져서 성능 저하가 발생하게 된다.