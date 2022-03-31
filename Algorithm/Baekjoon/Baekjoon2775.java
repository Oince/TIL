//백준 2775번 부녀회장이 될테야
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class Baekjoon2775 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testcase = Integer.parseInt(br.readLine());
        int k, n;
        int[] arr;
        while(testcase > 0) {
            k = Integer.parseInt(br.readLine());
            n = Integer.parseInt(br.readLine());
            arr = new int[n];
            for(int i = 0; i < arr.length; i++) {
                arr[i] = i + 1;
            }
            for(int i = 0; i < k; i++) {
                for(int j = 1; j < n; j++) {
                    arr[j] += arr[j - 1];
                }
            }
            System.out.println(arr[n-1]);
            testcase--;
        }
    }
}