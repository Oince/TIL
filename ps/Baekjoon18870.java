//https://www.acmicpc.net/problem/18870
//백준 18870 좌표 압축
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

public class Beakjoon18870 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        //원본 배열
        int[] arr = new int[n];
        //정렬할 배열
        int[] sorted = new int[n];

        //입력 값과 순위를 저장할 map
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < arr.length; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            sorted[i] = arr[i];
        }

        //배열 정렬
        Arrays.sort(sorted);

        //map에 저장
        int rank = 0;
        for (int i : sorted) {
            //중복된 키가 있으면 건너뜀
            if (!map.containsKey(i)) {
                map.put(i, rank++);
            }
        }

        //StringBulder를 이용하여 출력
        for (int i : arr) {
            //원본 값을 key로 삼아 map에서 순위 정보를 가져옴
            map.get(i);
            sb.append(map.get(i)).append(" ");
        }

        //출력
        System.out.println(sb);

    }
}