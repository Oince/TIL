//https://www.acmicpc.net/problem/1427
//백준 1427 소트인사이드
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Beakjoon1427 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //char배열로 입력 받음
        char[] input = br.readLine().toCharArray();
        int[] count = new int[10];

        //숫자 하나하나 쪼개서 각 숫자의 개수를 셈
        //그 결과를 count 배열에 저장
        for (int i = 0; i < input.length; i++) {
            count[input[i] - '0']++;
        }

        for (int i = 9; i >= 0; i--) {
            //count[i]가 0일 때 까지 i를 출력
            while (count[i] > 0) {
                System.out.print(i);
                count[i]--;
            }
        }
    }
}