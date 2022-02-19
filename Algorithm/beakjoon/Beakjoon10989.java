//https://www.acmicpc.net/problem/10989
//백준 10989 수 정렬하기 3
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Beakjoon10989 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());

        int[] input = new int[10001];
        //입력
        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(br.readLine());
            input[num]++; //입력한 수와 같은 인덱스에 카운팅 해줌
        }

        //출력
        for (int i = 0; i < input.length; i++) {
            //input[i]가 0보다 크면
            while (input[i] > 0) {
                //하나 줄이고 숫자 출력
                input[i]--;
                sb.append(i + "\n");
            }
        }

        System.out.println(sb);

    }

}