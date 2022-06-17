//https://www.acmicpc.net/problem/2609
//백준 2609 최대공약수와 최소공배수
import java.io.*;
import java.util.StringTokenizer;

public class Baekjoon2609 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        int g = gcd(a, b);
        int l = a * b / g;

        bw.write(g + "\n" + l);

        bw.flush();
        bw.close();

    }

    public static int gcd(int a, int b) {
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
}