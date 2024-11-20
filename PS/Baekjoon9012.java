//백준 9012번 괄호
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Stack;

public class Baekjoon9012 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        String input;
        Stack<Character> stack = new Stack();
        loop1 : while (t > 0) {
            stack.clear();
            input = br.readLine();
            for(int i = 0; i < input.length(); i++) {
                char ch = input.charAt(i);
                if (ch == '(') {
                    stack.push(ch);
                } else if (ch == ')') {
                    if (stack.empty()) {
                        System.out.println("NO");
                        t--;
                        continue loop1;
                    }
                    stack.pop();
                }
            }
            if (stack.empty()) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
            t--;
        }
    }
}