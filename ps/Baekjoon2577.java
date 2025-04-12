//백준 2577번 숫자의 개수
import java.util.Scanner;
public class Baekjoon2577 {
    public static void main(String[] args){
        int a,b,c,mul;
        int[] num = new int[10];
        Scanner in = new Scanner(System.in);
        a = in.nextInt();
        b = in.nextInt();
        c = in.nextInt();
        in.close();
        mul = a * b * c;
        while(mul != 0) {
            num[mul%10]++;
            mul = mul/10;
        }
        for(int i = 0; i < 10; i++) {
            System.out.println(num[i]);
        }
        
    }
}
