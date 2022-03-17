//https://www.acmicpc.net/problem/15649
//백준 15649번 N과 M(1)

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Beakjoon15649 {

    private static int[] arr;
    private static int n;
    private static int m;
    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        arr = new int[m];

        sequence(0);

        System.out.println(sb);

    }

    //dfs를 이용하여 탐색
    static void sequence(int i) {

        if (promising(i)) {
            if (i == m) {
                for (int i1 : arr) {
                    sb.append(i1 + " ");
                }
                sb.append("\n");
            } else {
                for (int j = 1; j <= n; j++) {
                    arr[i] = j;
                    sequence(i + 1);
                }
            }
        }

    }

    //유망한 노드 판별
    static boolean promising(int i) {

        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                if (arr[j] == arr[k]) {
                    return false;
                }
            }
        }
        return true;
    }
}