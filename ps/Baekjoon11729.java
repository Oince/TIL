//백준 11729 하노이 탑 이동 순서
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Baekjoon11729 {

    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        sb.append((int)Math.pow(2, n) - 1).append('\n');
        hanoi(n, 1, 2, 3);

        System.out.println(sb);
    }

    static void hanoi(int n, int start, int mid, int dest) {
        if (n == 1) {
            sb.append(start + " " + dest + "\n");
            return;
        }

        hanoi(n - 1, start, dest, mid);

        sb.append(start + " " + dest + "\n");

        hanoi(n - 1, mid, start, dest);

    }

}