//https://www.acmicpc.net/problem/10866
//백준 10866 덱
import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Baekjoon10866 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        Deque<Integer> list = new ArrayDeque<>();

        int n = Integer.parseInt(br.readLine());
        int x;

        while (n != 0) {
            st = new StringTokenizer(br.readLine());
            String command = st.nextToken();

            switch (command) {
                case "push_front":
                    x = Integer.parseInt(st.nextToken());
                    list.addFirst(x);
                    break;
                case "push_back":
                    x = Integer.parseInt(st.nextToken());
                    list.addLast(x);
                    break;
                case "pop_front":
                    if (list.isEmpty()) {
                        bw.write("-1\n");
                        break;
                    }
                    bw.write(list.removeFirst() + "\n");
                    break;
                case "pop_back":
                    if (list.isEmpty()) {
                        bw.write("-1\n");
                        break;
                    }
                    bw.write(list.removeLast() + "\n");
                    break;
                case "size":
                    bw.write(list.size() + "\n");
                    break;
                case "empty":
                    if (list.isEmpty())
                        bw.write("1\n");
                    else
                        bw.write("0\n");
                    break;
                case "front":
                    if (list.isEmpty()) {
                        bw.write("-1\n");
                        break;
                    }
                    bw.write(list.peekFirst() + "\n");
                    break;
                case "back":
                    if (list.isEmpty()) {
                        bw.write("-1\n");
                        break;
                    }
                    bw.write(list.peekLast() + "\n");
                    break;
            }
            n--;
        }

        bw.flush();
        bw.close();

    }
}