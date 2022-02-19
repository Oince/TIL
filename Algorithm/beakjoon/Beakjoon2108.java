//https://www.acmicpc.net/problem/2108
//백준 2108 통계학

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Beakjoon2108 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[] arr = new int[n];
        int[] sortedArr = new int[n];
        //입력
        for (int i = 0; i < arr.length; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        int i;

        //산술평균 출력
        int mean = 0;
        for (i = 0; i < arr.length; i++) {
            mean += arr[i];
        }
        System.out.printf("%.0f\n", (float) mean / n);

        //빈도 수 배열 입력
        int[] count = new int[8001];
        for (i = 0; i < arr.length; i++) {
            count[arr[i] + 4000]++;
        }

        //최빈값 계산
        int mode, modeIndex = 0;
        for (i = 1; i < count.length; i++) {
            if (count[modeIndex] < count[i]) {
                modeIndex = i;
            }
        }

        if (modeIndex != count.length - 1) {
            for (i = modeIndex + 1; i < count.length; i++) {

                if (count[modeIndex] == count[i]) {
                    modeIndex = i;
                    break;
                }
            }
        }
        mode = modeIndex - 4000;

        //카운팅 정렬
        for (i = 1; i < count.length; i++) {
            count[i] += count[i - 1];
        }

        for (i = arr.length - 1; i >= 0; i--) {
            int value = arr[i];
            count[value + 4000]--;
            sortedArr[count[value + 4000]] = value;
        }

        //중앙값 출력
        System.out.println(sortedArr[n / 2]);

        //최빈값 출력
        System.out.println(mode);

        //범위 출력
        System.out.println(sortedArr[n - 1] - sortedArr[0]);

//        ArrayList<Integer> list = new ArrayList<>();
//        for (int i = 0; i < n; i++) {
//            list.add(Integer.parseInt(br.readLine()));
//        }
//        //정렬
//        Collections.sort(list);
//
//        //1. 산술평균
//        int mean = 0;
//        for (Integer integer : list) {
//            mean += integer;
//        }
//        System.out.printf("%.0f\n", (float)mean / n);
//
//        //2. 중앙값
//        System.out.println(list.get(n / 2));
//
//        //3. 최빈값
//        int[] arr = new int[8001];
//        for (int i = 0; i < n; i++) {
//            arr[list.get(i) + 4000]++;
//        }
//
//        int modeIndex = 0;
//        for (int i = 1; i < arr.length; i++) {
//            if (arr[modeIndex] < arr[i]) {
//                modeIndex = i;
//            }
//        }
//
//        if (modeIndex == arr.length - 1) {
//            System.out.println(modeIndex - 4000);
//        } else {
//            for (int i = modeIndex + 1; i < arr.length; i++) {
//
//                if (arr[modeIndex] == arr[i]) {
//                    modeIndex = i;
//                    break;
//                }
//            }
//            System.out.println(modeIndex - 4000);
//        }
//
//        //4. 범위
//        System.out.println(list.get(n - 1) - list.get(0));

    }
}