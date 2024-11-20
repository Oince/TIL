//https://www.acmicpc.net/problem/18111
//백준 18111 마인크래프트
import java.io.*;

public class Baekjoon18111 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int m = Integer.parseInt(str[1]);
        int b = Integer.parseInt(str[2]);

        int[][] ground = new int[n][m];

        int maxHeight = -1;
        int minHeight = 257;

        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                ground[i][j] = Integer.parseInt(input[j]);
                if (maxHeight < ground[i][j]) {
                    maxHeight = ground[i][j];
                } else if (minHeight > ground[i][j]) {
                    minHeight = ground[i][j];
                }
            }
        }

        int minTime = Integer.MAX_VALUE;
        int index = 0;
        for (int height = minHeight; height <= maxHeight; height++) {
            int remove = 0;
            int build = 0;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int value = ground[i][j] - height;
                    if (value < 0) {
                        build -= value;
                    } else {
                        remove += value;
                    }
                }
            }

            if (remove + b >= build) {
                int time = remove * 2 + build;
                if (minTime >= time) {
                    minTime = time;
                    index = height;
                }
            }
        }

        System.out.println(minTime + " " + index);
    }
}