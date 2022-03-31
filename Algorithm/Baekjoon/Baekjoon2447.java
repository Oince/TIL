//백준 2447 별찍기 - 10
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Baekjoon2447 {

    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        //출력을 2차원 배열처럼 생각
        //i가 행 j 가 열
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                star(i, j, n);
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }

    static void star(int i, int j, int n) {
        if (i / n % 3 == 1 && j / n % 3 == 1) {
            sb.append(" ");
        } else if (n / 3 == 0) {
            sb.append("*");
        } else {
            star(i, j, n / 3);
        }
    }
}