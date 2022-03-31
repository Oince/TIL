//백준 8958번 OX퀴즈
import java.util.Scanner;
public class Baekjoon8958 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n, score = 0, count = 0;
        char[] OX;
        n = sc.nextInt();
        sc.nextLine();

        for(int i = 0; i < n; i++) {
            OX = sc.nextLine().toCharArray();
            for(int j = 0; j < OX.length; j++) {
                if(OX[j] == 'O') {
                    count++;
                    score += count;
                }
                else {
                    count = 0;
                }
            }
            count = 0;
            System.out.println(score);
            score = 0;
        }
        sc.close();
    }
}
