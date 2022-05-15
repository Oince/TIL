//https://www.acmicpc.net/problem/10816
//백준 10816 숫자 카드2
import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Baekjoon10816 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        Map<Integer, Integer> map = new HashMap<>(n);

        StringTokenizer st = new StringTokenizer(br.readLine());
        int input;

        for (int i = 0; i < n; i++) {
            input = Integer.parseInt(st.nextToken());
            if (map.containsKey(input)) {
                map.put(input, map.get(input) + 1);
            } else {
                map.put(input, 1);
            }
        }

        int m = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        int num;

        for (int i = 0; i < m; i++) {
            num = Integer.parseInt(st.nextToken());
            bw.write(map.getOrDefault(num, 0) + " ");
        }

        bw.flush();
        bw.close();
    }
}