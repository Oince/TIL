//https://www.acmicpc.net/problem/11866
//백준 11866 요세푸프 문제 0

import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

public class Baekjoon11866 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        sb.append("<");

        String[] input = br.readLine().split(" ");

        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        int i;

        Queue<Integer> q = new LinkedList<>();
        for (i = 1; i <= n; i++) {
            q.add(i);
        }

        while (!q.isEmpty()) {
            for (i = 1; i < m; i++) {
                q.add(q.remove());
            }
            int pop = q.remove();
            sb.append(pop).append(", ");
        }

        sb.setLength(sb.length() - 2);
        sb.append(">");

        System.out.println(sb);

    }
}