//백준 1929번 소수 구하기
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
public class Baekjoon1929 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        boolean[] arr = new boolean[n + 1];
        arr[0] = arr[1] = true;
        for(int i = 2; i <= Math.sqrt(n); i++) {
            if(arr[i] == false){
                for(int j = i * 2; j <= n; j = j + i) {
                    arr[j] = true;
                }
            }
        }
        for(int i = m; i <= n; i++) {
            if(arr[i] == false){
                System.out.println(i);
            }
        }

        // for(int i = 2; i <= n; i++) {
        //     if(arr[i])
        //         continue;
        //     if(m <= i){
        //         System.out.println(i);
        //     }
        //     for(int j = i * 2; j <= n; j = j + i) {
        //         arr[j] = true;
        //     }
        // }
    }
}
