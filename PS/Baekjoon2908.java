//백준 2908번 상수
import java.io.*;
import java.util.StringTokenizer;
public class Baekjoon2908 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(new StringBuilder(st.nextToken()).reverse().toString());
        int b = Integer.parseInt(new StringBuilder(st.nextToken()).reverse().toString());
        System.out.println(a > b ? a : b);
    }
}
