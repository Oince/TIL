//https://www.acmicpc.net/problem/15829
//백준 15829 hashing
import java.io.*;

public class Baekjoon15829 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long r = 1;
        int m = 1234567891;

        int l = Integer.parseInt(br.readLine());

        char[] str = br.readLine().toCharArray();

        long sum = 0;

        for (int i = 0; i < l; i++) {
            int c = str[i] - 96;
            sum += ((c % m) * (r % m)) % m;
            r = (r * 31) % m;
        }
        sum = sum % m;
        System.out.println(sum);


    }
}