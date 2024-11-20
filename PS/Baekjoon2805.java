//https://www.acmicpc.net/problem/2805
//백준 2805 나무 자르기
import java.io.*;

public class Baekjoon2805 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] num = br.readLine().split(" ");
        int n = Integer.parseInt(num[0]);
        int m = Integer.parseInt(num[1]);
        String[] tmp = br.readLine().split(" ");
        int[] height = new int[n];

        int i, low = 0, high = 0;

        for (i = 0; i < n; i++) {
            height[i] = Integer.parseInt(tmp[i]);
            if (high < height[i]) {
                high = height[i];
            }
        }
        int mid = 0;
        while (low < high) {
            mid = (low + high) / 2;
            long sum = 0;
            for (i = 0; i < n; i++) {
                if (height[i] > mid) {
                    sum += height[i] - mid;
                }
            }

            if (sum < m) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        System.out.println(low - 1);

    }
}