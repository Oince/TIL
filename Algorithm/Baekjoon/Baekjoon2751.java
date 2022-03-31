//백준 2751 수 정렬하기 2
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Baekjoon2751 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        ArrayList<Integer> input = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            input.add(Integer.parseInt(br.readLine()));
        }

        Collections.sort(input);

        for (int value : input) {
            sb.append(value).append('\n');
        }
        System.out.println(sb);
    }
}
