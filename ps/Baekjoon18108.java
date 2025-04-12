//https://www.acmicpc.net/problem/18108
//백준 18108 1998년생인 내가 태국에서는 2541년생?!
import java.io.*;

public class Baekjoon18108 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        System.out.println(n - 543);
    }
}