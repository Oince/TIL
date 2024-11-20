//https://www.acmicpc.net/problem/11650
//백준 11650 좌표 정렬하기
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Beakjoon11650 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        //arr[i][0] 은 i번쨰 점의 x좌표
        //arr[i][1] 은 i번쨰 점의 y좌표
        int[][] arr = new int[n][2];

        //입력
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }

        //Comparator를 재정의하여 정렬
        Arrays.sort(arr, (p1, p2) -> {
                    if (p1[0] == p2[0]) {
                        return p1[1] - p2[1];
                    } else {
                        return p1[0] - p2[0];
                    }
                });

        //출력
        for (int[] ints : arr) {
            for (int i : ints) {
                bw.write(String.valueOf(i) + " ");
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }

}