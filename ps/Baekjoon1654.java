//https://www.acmicpc.net/problem/1654
//백준 1654번 랜선 자르기
import java.io.*;

public class Baekjoon1654 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        int k = Integer.parseInt(input[0]);
        int n = Integer.parseInt(input[1]);

        int[] number = new int[k];
        int i;
        long high = 0L;
        for (i = 0; i < number.length; i++) {
            number[i] = Integer.parseInt(br.readLine());
            if (high < number[i]) {
                high = number[i];
            }
        }

        long low = 1, count = 0;
        long mid;

        while (low <= high) {
            mid = (low + high) / 2;
            for (i = 0; i < k; i++) {
                count += number[i] / mid;
            }
            if (count >= n) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
            count = 0;
        }

        System.out.println(low - 1);

    }
}