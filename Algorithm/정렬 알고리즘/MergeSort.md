# 합병 정렬(Merge Sort)
## 합병 정렬 이란?
분할 정복 기법을 이용하는 정렬 알고리즘 중 하나.  
배열의 길이가 1개가 될 때 까지 분할한 후 합치면서 정렬한다.  
### 과정
1. 배열를 두 개로 쪼갠다.
2. 쪼개진 배열의 길이가 1이면 이미 정렬된 것으로 본다.  
길이가 1보다 크다면 1이 될 때 까지 다시 쪼갠다.
3. 쪼개진 배열을 합치면서 정렬한다.

<img src="https://t1.daumcdn.net/cfile/tistory/214EFE385452034624">

코드(java)  
```java
void mergeSort(int[] input) {
    mergeSort(0, input.length - 1);
}

void mergeSort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        //분할
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        //합병
        merge(low, mid, high);
    }
}

void merge(int low, int mid, int high) {
    //정렬에 사용할 임시 지역 배열 선언
    int[] tmp = new int[high + 1];

    int i, j, index;
    i = low;
    j = mid + 1;
    index = low;

    //두 배열에서 값을 하나씩 비교하여 임시 배열에 넣음
    while (i <= mid && j <= high) {
        if (input[i] > input[j]) {
            tmp[index++] = input[j++];
        } else {
            tmp[index++] = input[i++];
        }
    }

    //만약 왼쪽 배열이 비었다면
    if (i > mid) {
        //오른쪽 배열을 임시 배열에 넣음
        for (int k = j; k <= high; k++) {
            tmp[index++] = input[k];
        }
    //오른쪽 배열이 비었다면    
    } else {
        //왼쪽 배열을 임시 배열에 넣음
        for (int k = i; k <= mid; k++) {
            tmp[index++] = input[k];
        }
    }

    //임시 배열을 원래 배열에 복사
    for (i = low; i <= high; i++) {
        input[i] = tmp[i];
    }
}
```
### 특징
제자리 정렬 알고리즘이 아니다.  
#### 제자리 정렬이란?
정렬할 때 추가적인 공간이 필요하지 않은 알고리즘.  
합병 정렬은 추가적인 지역 배열이 필요하기 때문에 제자리 정렬 알고리즘이 아니다.  
  
시간 복잡도 - O(nlogn)  
입력 크기 n 을 2^k라고 가정하면,  
재귀 호출 횟수는 k(log n)번, 비교 연산의 최대 횟수는 n번이다. 
(각 단계의 원소의 총 개수 -> n개)  
따라서 O(nlogn)
  
공간 복잡도 - O(n)  
merge 함수에서 사용하는 지역배열의 최대 크기는 input배열의 크기이다.

    
    
