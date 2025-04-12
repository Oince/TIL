//백준 2292번 벌집
import java.io.*;
public class Baekjoon2292 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int input = Integer.parseInt(br.readLine());
        int i = 1, count = 1;
        while(i < input){
            i = i + count * 6;
            count ++;
        }
        System.out.println(count);
    } 
}
