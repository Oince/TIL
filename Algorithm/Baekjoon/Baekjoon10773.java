//https://www.acmicpc.net/problem/10773
//백준 10773 제로
import java.io.*;

public class Baekjoon10773 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int k = Integer.parseInt(br.readLine());
        int[] store = new int[k];


        int n, length = -1;
        for (int i = 0; i < k; i++) {
            n = Integer.parseInt(br.readLine());
            if (n == 0) {
                length--;
            } else {
                store[++length] = n;
            }
        }

        int sum = 0;
        for (int i = 0; i <= length; i++) {
            sum += store[i];
        }

        System.out.println(sum);
    }
}