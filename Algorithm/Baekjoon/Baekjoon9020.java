//백준 9020번 골드바흐의 추측
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class Baekjoon9020 {
   public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] prime = new boolean[10001];
        prime[0] = prime[1] = true;
        for(int i = 2; i <= 100; i++) {
            if(prime[i] == false) {
                for(int j = i * i; j <= 10000; j = j + i) {
                    prime[j] = true;
                }
            }
        }
        int T = Integer.parseInt(br.readLine());
        int n;
        while(T > 0) {
            n = Integer.parseInt(br.readLine());
            for(int i = n / 2; i <= n - 2; i++) {
                if(prime[i] == false && prime[n - i] == false) {
                    System.out.println((n - i) + " " + i);
                    break;
                }
            }
            T--;
        }
   }
}
