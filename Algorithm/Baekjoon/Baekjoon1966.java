//https://www.acmicpc.net/problem/1966
//백준 1966번 프린터 큐

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class Baekjoon1966 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        LinkedList<Integer> q = new LinkedList<>();

        while (t > 0) {
            String[] input = br.readLine().split(" ");
            int n = Integer.parseInt(input[0]);
            int m = Integer.parseInt(input[1]);
            String[] priority = br.readLine().split(" ");

            for (int i = 0; i < n; i++) {
                int item = Integer.parseInt(priority[i]);
                q.add(item);
            }

            int count = 0;
            while (!q.isEmpty()) {
                boolean flag = true;
                int item = q.remove();

                for (Integer i : q) {
                    if (item < i) {
                        q.add(item);
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    count++;
                    if (m == 0) {
                        break;
                    }
                    m--;
                } else {
                    if (m == 0) {
                        m = q.size() - 1;
                    } else {
                        m--;
                    }
                }
            }
            q.clear();
            System.out.println(count);

            t--;
        }

    }
}