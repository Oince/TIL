//백준 4948번 베르트랑 공준
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class Baekjoon4948 {
   public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, count = 0;
        boolean[] arr = new boolean[123456 * 2 + 1];
        arr[0] = arr[1] = true;
        for(int i = 2; i <= Math.sqrt(arr.length - 1); i++) {
            if(arr[i] == false){
                for(int j = i * 2; j < arr.length; j = j + i) {
                    arr[j] = true;
                }
            }
        }
        while(true) {
            n = Integer.parseInt(br.readLine());
            if(n == 0)
                break;
            for(int i = n + 1; i <= 2 * n; i++) {
                if(arr[i] == false){
                    count++;
                }
            }
            System.out.println(count);
            count = 0;
       }   
   }
}
