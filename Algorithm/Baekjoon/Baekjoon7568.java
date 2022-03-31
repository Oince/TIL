//https://www.acmicpc.net/problem/7568
//백준 7568번 덩치
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Beakjoon7568 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());

        //input[n][0] == 몸무게 , input[n][1] == 키
        int[][] input = new int[n][2];

        //입력
        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            input[i][0] = Integer.parseInt(st.nextToken());
            input[i][1] = Integer.parseInt(st.nextToken());
        }

        //입력 배열 탐색
        for (int i = 0; i < input.length; i++) {
            //순위를 저장하는 변수
            int rank = 1;
            for (int j = 0; j < input.length; j++) {
                //i번째 사람보다 키와 몸무게 둘 다 큰 사람이 있다면 순위 하나 증가
                if (input[i][0] < input[j][0] && input[i][1] < input[j][1]) {
                    rank++;
                }
            }
            //순위 출력
            System.out.print(rank + " ");
        }
    }

}
