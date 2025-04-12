//백준 3052번 나머지
import java.util.Scanner;
public class Baekjoon3052 {
    public static void main(String[] args) {
        int[] remainder = new int[42];
        Scanner sc = new Scanner(System.in);
        int count = 0;
        int input;
        for(int i = 0; i < 42; i++){
            remainder[i] = 0;
        }
        for(int i = 0; i < 10; i++) {
            input = sc.nextInt();
            remainder[input % 42]++;
        }
        sc.close();
        for(int i = 0; i < 42; i++) {
            if(remainder[i] > 0){
                count++;
            }
        }
        System.out.println(count);
    }
}
