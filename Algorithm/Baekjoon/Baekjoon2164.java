//백준 2164번 카드2
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Baekjoon2164 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Queue<Integer> queue = new LinkedList<>();

        for (int i = 1; i <= n; i++) {
            queue.add(i);
        }

        while (true) {
            if(queue.size() <= 1)
                break;
            queue.remove();
            Integer removeItem = queue.remove();
            queue.add(removeItem);
        }

        System.out.println(queue.peek());
    }
}