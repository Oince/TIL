//백준 1152번 단어의 개수
import java.io.*;
public class Baekjoon1152 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String sentence = br.readLine().trim();
        int count = 1;
        if(sentence.isBlank()){
            System.out.println('0');
            return;
        }
        for(int i = 1; i < sentence.length(); i++) {
            if(sentence.charAt(i) == ' ') {
                count++;
            }
        }
        System.out.println(count);
    }
}