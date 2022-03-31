//백준 1978번 소수 찾기
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
public class Baekjoon1978 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int num, count = 0;
        for(int i = 0; i < N; i++) {
            num = Integer.parseInt(st.nextToken());
            if(isPrime(num))
                count++;
        }
        System.out.println(count);
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