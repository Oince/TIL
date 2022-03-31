//백준 1193번 분수찾기
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class Baekjoon1193 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());
        int i = 1;
        while(num > i) {
            num = num - i;
            i++;
        }
        if(i % 2 == 1) {
            System.out.println((i + 1- num) + "/" + num);
        }
        else {
            System.out.println(num + "/" + (i + 1 - num));
        }
    }
}
