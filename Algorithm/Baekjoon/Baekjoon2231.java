//백준 2231번 분해합
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Baekjoon2231 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int result = 0;
        for (int i = 1; i < n; i++) {
            result += i;
            for (int j = i; j > 0; j = j / 10) {
                result += j % 10;
            }

            if (result == n) {
                System.out.println(i);
                return;
            } else {
                result = 0;
            }
        }
        System.out.println(0);
    }
}