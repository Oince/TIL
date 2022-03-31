//백준 4153번 직각삼각형
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.StringTokenizer;
public class Baekjoon4153 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] arr = new int[3];
        while(true){
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[0] = Integer.parseInt(st.nextToken());
            arr[1] = Integer.parseInt(st.nextToken());
            arr[2] = Integer.parseInt(st.nextToken());
            Arrays.sort(arr);
            if(arr[0] == 0)
                break;
            System.out.println((arr[0]*arr[0] + arr[1]*arr[1] == arr[2]*arr[2]) ? "right" : "wrong");
        }
    }
}