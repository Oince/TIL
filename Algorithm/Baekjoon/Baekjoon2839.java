//백준 2839번 설탕 배달
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class Baekjoon2839 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        //
        int bag = 0;
        while(n >= 0) {
            if(n % 5 == 0){
                bag += n / 5;
                System.out.println(bag);
                return;
            }
            n -= 3;
            bag++;
        }
        System.out.println("-1");
        // for(i = n / 5; i > 0; i--) {
        //     if((n - (i * 5)) % 3 == 0) {
        //         i += (n - (i * 5)) / 3;
        //         break;
        //     }
        // }
        // if(i == 0) {
        //     if((n % 3) == 0)
        //         System.out.println(n/3);
        //     else
        //         System.out.println("-1");
        // }
        // else {
        //     System.out.println(i);
        // }
    }
}
