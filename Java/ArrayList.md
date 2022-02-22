# ArrayList
## 소개
ArrayList는 List 인터페이스를 구현한 클래스이다.  
배열을 기반으로 구현하였으며 데이터의 저장 순서가 유지되고 중복을 허용한다.  
배열을 기반으로 구현하였기 때문에 값을 읽어오거나, 데이터를 순차적으로 추가/삭제 하는 경우에는 성능이 좋다  
하지만 중간에 데이터를 추가/삭제하는 경우에는 그 이후의 데이터들을 전부 이동해야 하기 때문에 LinkedList에 비해 성능이 좋지 않다.  
또한 초기 용량을 넘을 경우 더 큰 배열을 만들어서 복사하는 과정이 필요하다.  
이 과정에서 시간이 오래 걸리기 때문에 초기 용량을 잘 설정하는 것이 중요하다.  
ArrayList는 제네릭 클래스 이므로 <>안에 저장할 객체를 명시해주어야 한다.  

## 생성
기본 생성자는 크키가 10인 ArrayList를 만들어 준다.  
생성자에 인자로 정수를 넘기면 그 정수만큼의 크기를 가진 ArrayList를 만든다.  
다른 컬렉션을 인자로 넣을 수도 있다.
```java
//기본 생성자, 용량 10
ArrayList<Integer> list = new ArrayList<>();
//초기 용량 20으로 설정
ArrayList<Integer> list2 = new ArrayList<>(20);
//다른 컬렉션을 초기 상태로 지정할 수 있음
ArrayList<Integer> list3 = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5));
```

## 저장
데이터 저장은 add 메서드를 사용한다.  
인자를 하나만 넣으면 마지막 인덱스에 추가하고, 두 개를 넣으면 첫번째 인자가 넣을 위치, 두번째 인자가 넣을 값이다.  
addAll 메서드는 다른 컬렉션의 데이터를 저장하는 메서드이다.

```java
list.add(6); //마지막 인덱스에 추가
list.add(1, 7); // 지정된 위치에 값 추가, 인덱스가 마지막 인덱스보다 크면 에러 발생
list.addAll(list3); //주어진 컬렉션의 모든 원소 저장
list.addAll(2, list3);//지정된 인덱스부터 주어진 컬렉션의 모든 원소 저장
```

## 읽기
저장되어 있는 값을 읽을 때는 get 메서드를 사용한다.  
indexOf 메서드를 활용하면 해당 값이 위치해 있는 인덱스를 알 수 있다.
```java
int item = list.get(4); //4번 인덱스의 값 읽기
int index = list.indexOf(6); //6이 저장되어 있는 위치를 반환 
```

## 삭제
값을 리스트에서 삭제할 때는 remove 메서드를 사용한다.  
리스트에 저장되어 있는 모든 값을 삭제할 때에는 clear 메서드를 사용한다.
```java
list.remove(3); //지정된 인덱스의 값 삭제
Integer a = 4;
list.remove(a); //값 4를 찾아서 삭제
list.clear(); //리스트 전체 값 삭제
```

## 기타 유용한 메서드

### size()
저장된 객체의 개수를 리턴한다.
```java
list.size();
```

### isEmpty()
리스트가 비어있으면 true, 비어있지 않다면 false를 리턴한다.
```java
list.isEmpty();
```

### set()
지정된 위치의 값을 수정한다.
```java
list.set(2, 4); // 2번 인덱스의 값을 4로 수정
```

### toArray()
저장된 객체들을 객체 배열로 리턴한다.
```java
Integer[] a = list.toArray(new Integer[0]);
```
