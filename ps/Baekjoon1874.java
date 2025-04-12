//https://www.acmicpc.net/problem/1874
//백준 1874번 스택 수열
import java.io.*;
import java.util.Stack;

public class Baekjoon1874 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        int[] input = new int[n];

        int i;
        for (i = 0; i < n; i++) {
            input[i] = Integer.parseInt(br.readLine());
        }

        Stack<Integer> stack = new Stack<>();

        int count = 0;
        i = 0;
        stack.push(++count);
        sb.append("+\n");

        while (i < n) {
            if (input[i] == stack.peek()) {
                i++;
                stack.pop();
                sb.append("-\n");
                if (stack.isEmpty() && i != n) {
                    stack.push(++count);
                    sb.append("+\n");
                }
            } else if (input[i] < stack.peek()) {
                System.out.println("NO");
                return;
            } else {
                stack.push(++count);
                sb.append("+\n");
            }
        }
        System.out.println(sb);
    }
}