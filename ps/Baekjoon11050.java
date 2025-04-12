//https://www.acmicpc.net/problem/11050
//백준 11050 이항 계수 1
import java.io.*;

public class Baekjoon11050 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);

        int[][] arr = new int[n + 1][k + 1];

        if (n / 2 < k) {
            k = n - k;
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= Math.min(i ,k); j++) {
                if (j == 0 || i == j) {
                    arr[i][j] = 1;
                } else {
                    arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
                }
            }
        }

        bw.write(String.valueOf(arr[n][k]));
        bw.flush();
        bw.close();

    }
}