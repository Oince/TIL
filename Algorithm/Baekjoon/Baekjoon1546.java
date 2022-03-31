//백준 1546번 평균
import java.util.Scanner;
public class Baekjoon1546 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, M = 0;
        double sum = 0, tmp;
        n = sc.nextInt();
        int[] grade = new int[n];
        for(int i = 0; i < n; i++) {
            grade[i] = sc.nextInt();
            if(i == 0 || grade[i] > M) {
                M = grade[i];
            }
        }
        sc.close();
        for(int i = 0; i < n; i++) {
            tmp = (double)grade[i] / M * 100;
            sum += tmp;
        }
        System.out.println(sum / n);
    }
}
