//https://www.acmicpc.net/problem/1003
//백준 1003 피보나치 함수
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Beakjoon1003 {

    //계산 결과를 문자열로 변환해서 출력하기 위해 StringBuilder 사용
    private static final StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testcase = Integer.parseInt(br.readLine());

        //n의 최댓값 40만큼의 배열을 생성
        int[][] fibonacci = new int[41][2];
        //초기값 설정
        fibonacci[0][0] = 1;
        fibonacci[0][1] = 0;
        fibonacci[1][0] = 0;
        fibonacci[1][1] = 1;
        //40까지의 정답을 구함
        for (int i = 2; i < fibonacci.length; i++) {
            //점화식
            fibonacci[i][0] = fibonacci[i - 1][1];
            fibonacci[i][1] = fibonacci[i - 1][0] + fibonacci[i - 1][1];
        }

        while (testcase > 0) {
            int n = Integer.parseInt(br.readLine());
            //StringBuilder에 담아서 출력
            sb.append(fibonacci[n][0]).append(" ").append(fibonacci[n][1]);
            System.out.println(sb);
            //StringBuilder 초기화
            sb.setLength(0);
            testcase--;
        }
    }

}