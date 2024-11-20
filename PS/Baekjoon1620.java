//https://www.acmicpc.net/problem/1620
//백준 1620 나는야 포켓몬 마스터 이다솜

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Baekjoon1620 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String[] number = br.readLine().split(" ");
        int n = Integer.parseInt(number[0]);
        int m = Integer.parseInt(number[1]);

        String[] arr = new String[n + 1];
        Map<String, Integer> map = new HashMap<>();

        for (int i = 1; i <= n; i++) {
            String str = br.readLine();
            arr[i] = str;
            map.put(str, i);
        }

        for (int i = 0; i < m; i++) {
            String str = br.readLine();
            if (str.chars().allMatch( Character::isDigit )) {
                int num = Integer.parseInt(str);
                sb.append(arr[num]).append("\n");
            } else {
                sb.append(map.get(str)).append("\n");
            }
        }
        System.out.println(sb);
    }
}