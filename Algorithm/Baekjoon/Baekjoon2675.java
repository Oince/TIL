//백준 2675번 문자열 반복
import java.io.*;
public class Baekjoon2675 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, repeat;
        String input;
        String output = "";
        n = Integer.parseInt(br.readLine());
        for(int i = 0; i < n; i++) {
            input = br.readLine();
            repeat = input.charAt(0) - '0';
            input = input.substring(2);
            for(int j = 0; j < input.length(); j++) {
                for(int k = 0; k < repeat; k++){
                    output = output + input.substring(j, j + 1);
                }
            }
            System.out.println(output);
            output = "";
        }
    }
}