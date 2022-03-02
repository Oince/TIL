//https://www.acmicpc.net/problem/1181
//백준 1181 단어정렬
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

public class Beakjoon1181 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());

        //중복 제거를 위해 set으로 받음
        Set<String> input = new HashSet<>();
        for (int i = 0; i < n; i++) {
            input.add(br.readLine());
        }

        //정렬하기 위해 list로 변환
        ArrayList<String> strings = new ArrayList<>(input);

        //Comparator를 재정의하여 정렬
        Collections.sort(strings, (s1, s2) -> {
            if (s1.length() > s2.length()) {
                return 1;
            } else if (s1.length() < s2.length()) {
                return -1;
            } else {
                for (int i = 0; i < s1.length(); i++) {
                    if (s1.charAt(i) > s2.charAt(i)) {
                        return 1;
                    } else if (s1.charAt(i) < s2.charAt(i)) {
                        return -1;
                    }
                }
                return 0;
            }
        });

        //출력
        for (String s : strings) {
            sb.append(s).append("\n");
        }
        System.out.println(sb);




    }
}