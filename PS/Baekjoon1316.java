//백준 1316번 그룹 단어 체커
import java.io.*;
public class Baekjoon1316 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] alphabet = new int[26];
        int count = 0;
        boolean flag = true;
        int N = Integer.parseInt(br.readLine());
        for(int i = 0; i < N; i++) {
            String input = br.readLine();
            alphabet[input.charAt(0) - 'a']++;
            for(int j = 1; j < input.length(); j++) {
                int ch = input.charAt(j) - 'a';
                int preCh = input.charAt(j - 1) - 'a';
                if(alphabet[ch] == 0) 
                    alphabet[ch]++;
                else if(ch == preCh)
                    alphabet[ch]++;
                else{
                    flag = false;
                    break;
                }
            }
            if(flag)
                count++;
            else
                flag = true;
            for(int k = 0; k < alphabet.length; k++){
                alphabet[k] = 0;
            }
        }
        System.out.println(count);
    }
}
