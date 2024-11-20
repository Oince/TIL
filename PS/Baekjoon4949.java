//https://www.acmicpc.net/problem/4949
//백준 4949 균형잡힌 세상
import java.io.*;
import java.util.Stack;

public class Baekjoon4949 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Stack<Character> bracket = new Stack<>();

        while (true) {
            char[] input = br.readLine().toCharArray();
            if (input[0] == '.') {
                break;
            }
            boolean flag = true;
            for (int i = 0; i < input.length - 1; i++) {
                char item = input[i];
                if (item == '(' || item == '[') {
                    bracket.push(item);
                } else if (item == ')' || item == ']') {
                    if (bracket.isEmpty()) {
                        flag = false;
                        break;
                    } else if ((bracket.peek() == '(' && item == ']') || (bracket.peek() == '[' && item == ')')) {
                        flag = false;
                        break;
                    } else {
                        bracket.pop();
                    }
                }
            }
            if (flag && bracket.isEmpty()) {
                bw.write("yes\n");
            } else {
                bw.write("no\n");
            }
            bracket.clear();
        }
        bw.flush();
        bw.close();
    }
}