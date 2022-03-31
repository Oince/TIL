//백준 2941번 크로아티아 알파벳
import java.io.*;
public class Baekjoon2941 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        String dz = "dz=";
        int count = 0;
        int i = 0;
        char currentChar;
        char nextChar;
        while(i < input.length()) {
            currentChar = input.charAt(i);
            if(i < input.length() - 2 && dz.equals(input.substring(i, i + 3))){
                i += 3;
            }
            else if(i < input.length() - 1) {
                nextChar = input.charAt(i + 1);
                if(nextChar == '-' || nextChar == '=') {
                    i += 2;
                }
                else if((currentChar == 'l' || currentChar == 'n') && nextChar == 'j') {
                    i += 2;
                }
                else{
                    i++;
                }
            }
            else {
                i++;
            }
            count++;
        }
        System.out.println(count);
    }
}
