//백준 1712번 손익분기점
import java.io.*;
import java.util.StringTokenizer;
public class Baekjoon1712 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        if(c <= b){
            System.out.println(-1);
        }
        else{
            System.out.println(a / (c - b) + 1);
        }
    }
}
