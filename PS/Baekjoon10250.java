//백준 10250번 ACM호텔
import java.io.*;
import java.util.StringTokenizer;
public class Baekjoon10250 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int H, W, N;
        int T = Integer.parseInt(br.readLine());
        for(int i = 0; i < T; i++) {
            st = new StringTokenizer(br.readLine());
            H = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());
            N = Integer.parseInt(st.nextToken());
            
            if(N % H == 0) {
                System.out.printf("%d%02d\n", H, N / H);
            }
            else {
                System.out.printf("%d%02d\n", N % H, N / H + 1);
            }
        }
    }
}
