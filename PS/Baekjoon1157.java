//백준 1157번 단어 공부
import java.io.*;
public class Baekjoon1157 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] alphabet = new int[26];
        int tmp, maxIndex = -2, maxValue = -1;
        String word = br.readLine().toUpperCase();
        br.close();
        for(int i = 0; i < word.length(); i++) {
            tmp = word.charAt(i) - 'A';
            alphabet[tmp]++;            
        }
        for(int i = 0; i < alphabet.length; i++) {
            if(maxValue < alphabet[i]) {
                maxValue = alphabet[i];
                maxIndex = i;
            }
            else if(maxValue == alphabet[i]) {
                maxIndex = -2;
            }
        }
        System.out.println((char)(maxIndex + 'A'));
    }    
}
