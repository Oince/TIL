# 카운팅 정렬(Counting Sort)
## 소개
카운팅 정렬은 값을 서로 비교하지 않고 값들의 개수를 세어서 정렬하는 알고리즘이다.  
## 과정
입력 배열이 다음과 같다고 하자.
```java
int[] input = {4, 3, 7, 5, 3, 4, 7, 8, 9, 1, 1, 2, 4, 5, 6};
```
1. 입력 값의 최대값만큼의 크기를 가진 counting배열을 선언한다.  
    ```java
    //입력 최대값 9
    int[] counting = new int[10];
    ```
2. 입력 값과 같은 인덱스에 1씩 더해준다.  
    ```java
    for (int i = 0; i < input.length; i++) {
        counting[input[i]]++;
    }
    ```
    >counting 배열 = 
    { 0, 2, 1, 2, 3, 2, 1, 2, 1, 1 }
3. counting 배열의 값들을 누적 합으로 바꾼다.
    ```java
    for (int i = 1; i < counting.length; i++) {
        counting[i] += counting[i - 1];
    }
    ```
    >counting 배열 = { 0, 2, 3, 5, 8, 10, 11, 13, 14, 15 }

4. counting 배열의 값을 통해 정렬된 결과 배열을 만든다.  
    ```java
    for (int i = input.length - 1; i >= 0; i--) {
        counting[input[i]]--;
        result[counting[input[i]]] = input[i];
    }
    ```

## 특징
시간 복잡도 - O(n + k) (k는 최댓값)  
공간 복잡도 - O(k)  
  
k에 따라 성능이 달라진다.  
k가 작다면 O(n)으로 성능이 매우 뛰어나지만, k가 커진다면 메모리의 낭비가 심해진다.
  
> 10개의 원소를 정렬하는데 k가 21억이라면?  
21억개의 원소가 들어가는 배열을 만들어야한다. -> 엄청난 메모리 낭비

## 코드
```java
public class CountingSort {
    public static void main(String[] args) {
        //입력 배열
        int[] input = {4, 3, 7, 5, 3, 4, 7, 8, 9, 1, 1, 2, 4, 5, 6};
        //결과 배열
        int[] result = new int[input.length];
        //입력 최대값 9
        //0 ~ 9까지의 숫자 저장
        int[] counting = new int[10];

        //입력 값과 같은 인덱스에 1씩 더해줌
        for (int i = 0; i < input.length; i++) {
            counting[input[i]]++;
        }

        //누적합으로 변경
        for (int i = 1; i < counting.length; i++) {
            counting[i] += counting[i - 1];
        }

        //결과 배열에 저장
        for (int i = input.length - 1; i >= 0; i--) {
            counting[input[i]]--;
            result[counting[input[i]]] = input[i];
        }

        //출력
        for (int i = 0; i < result.length; i++) {
            System.out.println(result[i]);
        }
    }
}
```












