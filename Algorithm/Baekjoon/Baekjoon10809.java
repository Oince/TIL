//백준 10809번 알파벳 찾기
import java.io.*;
public class Baekjoon10809 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String word = br.readLine();
        br.close();
        for(int i = 'a'; i <= 'z'; i++) {
            System.out.print(word.indexOf(i) + " ");
        }
    }
}
