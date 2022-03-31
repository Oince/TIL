//백준 2750번 수 정렬하기
//O(n^2)인 정렬 알고리즘
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Baekjoon2750 {

    private static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
//        bubbleSort();
//        selectionSort();
        insertionSort();
        for (int i : arr) {
            System.out.println(i);
        }
    }

    static void insertionSort() {
        int i, j, key;
        for (i = 1; i < arr.length; i++) {
            key = arr[i];
            for (j = i - 1; j >= 0 && key < arr[j]; j--) {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = key;
        }
    }

    static void selectionSort() {
        int i, j, minIndex, tmp;
        for (i = 0; i < arr.length - 1; i++) {
            minIndex = i;
            for (j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }

    static void bubbleSort() {
        int tmp;
        for (int i = arr.length - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (arr[j] > arr[j + 1]) {
                    tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
        }
    }

}