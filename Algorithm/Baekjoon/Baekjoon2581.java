//백준 2581번 소수
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class Baekjoon2581 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int m = Integer.parseInt(br.readLine());
        int n = Integer.parseInt(br.readLine());
        int sum = 0, min = 0;
        for(int i = m; i <= n; i++) {
            if(isPrime(i)) {
                if(sum == 0){
                    min = i;
                }
                sum += i;
            }
        }
        if(sum == 0){
            System.out.println("-1");
        }
        else{
            System.out.printf("%d\n%d", sum, min);
        }
    }   

    public static boolean isPrime(int num) {
        if(num == 1) 
            return false;
        for(int i = 2; i <= Math.sqrt(num); i++) {
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }
}
