//https://www.acmicpc.net/problem/1436
//백준 1436번 영화감독 숌
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Beakjoon1436 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int number = 665;

        while (n > 0) {

            //1씩 증가시키면서 종말의 숫자인지 아닌지를 판별함
            int endNumber = ++number;
            //종말의 숫자인지 아닌지를 알려주는 변수
            boolean isEndNumber = false;
            int count = 0;

            //자릿수 별로 쪼개서 검사
            while (endNumber > 0) {
                int num = endNumber % 10;
                endNumber = endNumber / 10;

                //num이 6이면 count하나 증가
                if (num == 6) {
                    count++;
                    //count가 3일 떄 종말의 숫자임
                    if (count == 3) {
                        isEndNumber = true;
                        break;
                    }
                }
                //num이 6이 아니면 count 초기화
                else {
                    count = 0;
                }
            }

            //종말의 숫자일 때 n을 1감소
            if (isEndNumber) {
                n--;
            }
        }
        System.out.println(number);
    }
}
