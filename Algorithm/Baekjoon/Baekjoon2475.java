//백준 2475번 검증수
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Baekjoon2475 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int sum = 0;
        while(st.hasMoreTokens()) {
            int n = Integer.parseInt(st.nextToken());
            sum += n * n;
        }
        System.out.println(sum % 10);
    }
}