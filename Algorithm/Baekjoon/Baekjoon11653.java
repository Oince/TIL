//백준 11653번 소인수분해
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class Baekjoon11653 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if(n == 1) 
            return;
        for(int i = 2; i <= Math.sqrt(n); i++) {
            while(n % i == 0) {
                System.out.println(i);
                n = n / i;
            }
        }
        if(n != 1)
            System.out.println(n);
    }

}
