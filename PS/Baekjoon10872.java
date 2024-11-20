//백준 10872 팩토리얼
import java.io.*;
public class Baekjoon10872 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        System.out.println(fac(n));
    }

    public static int fac(int n) {
        if(n <= 1){
            return 1;
        }
        else {
            return n * fac(n - 1);
        }
    }
}
