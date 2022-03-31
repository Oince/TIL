//백준 5622번 다이얼
import java.io.*;
public class Baekjoon5622 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        int[] number = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
        int time = 0;
        int ch;

        for(int i = 0; i < input.length(); i++) {
            ch = input.charAt(i) - 'A';
            time += number[ch];
        }
        System.out.println(time);
    }
}
