//https://www.acmicpc.net/problem/10815
//백준 10815번 숫자 카드
import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Baekjoon10815 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st;

        Set<Integer> card = new HashSet<>();
        int n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        while (st.hasMoreTokens()) {
            card.add(Integer.parseInt(st.nextToken()));
        }

        int m = Integer.parseInt(br.readLine());
        int[] compare = new int[m];
        int i;
        st = new StringTokenizer(br.readLine());
        for (i = 0; i < m; i++) {
            compare[i] = Integer.parseInt(st.nextToken());
        }

        for (i = 0; i < m; i++) {
            if (card.contains(compare[i])) {
                compare[i] = 1;
            } else {
                compare[i] = 0;
            }
        }

        for (i = 0; i < m; i++) {
            bw.write(compare[i] + " ");
        }

        bw.flush();
        bw.close();

    }
}