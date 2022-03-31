//백준 10828번 스택
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Baekjoon10828 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        String command;
        int number;
        Stack stack = new Stack();
        int n = Integer.parseInt(br.readLine());
        while(n > 0) {
            st = new StringTokenizer(br.readLine());
            command = st.nextToken();
            switch (command) {
                case "push":
                    number = Integer.parseInt(st.nextToken());
                    stack.push(number);
                    break;
                case "pop":
                    stack.pop();
                    break;
                case "size":
                    stack.size();
                    break;
                case "empty":
                    stack.empty();
                    break;
                case "top":
                    stack.top();
                    break;
                default :
            }
            n--;
        }
    }
}

class Stack {

    private int[] stack = new int[10];
    private int length = 0;
    private int size = 10;

    private void sizeUp() {
        size = size * 2;
        int[] tmp = new int[size];
        System.arraycopy(stack, 0, tmp, 0, stack.length);
        stack = tmp;
    }

    public void push(int x) {
        if(length >= size) {
            sizeUp();
        }
        stack[length++] = x;
    }

    public void pop() {
        if(length <= 0) {
            System.out.println(-1);
            return;
        }
        int pop = stack[--length];
        System.out.println(pop);
    }

    public void size() {
        System.out.println(length);
    }

    public void empty() {
        if(length > 0) {
            System.out.println(0);
        }
        else {
            System.out.println(1);
        }
    }

    public void top() {
        if(length <= 0) {
            System.out.println(-1);
            return;
        }
        System.out.println(stack[length - 1]);
    }
}