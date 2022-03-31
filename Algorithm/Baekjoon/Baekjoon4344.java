//백준 4344 평균은 넘겠지
import java.util.Scanner;
public class Baekjoon4344 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int c, n, count = 0, sum = 0;
        float avg;
        int[] score;
        
        c = sc.nextInt();
        for(int i = 0; i < c; i++) {
            n = sc.nextInt();
            score = new int[n];
            for(int j = 0; j < n; j++) {
                score[j] = sc.nextInt();
                sum += score[j];
            }
            avg = (float)sum / n;
            for(int j = 0; j < n; j++) {
                if(score[j] > avg)
                count++;
            }
            System.out.printf("%.3f%%\n", (float)count / n * 100);
            sum = 0;
            count = 0;
        }
        sc.close();
    }
}
