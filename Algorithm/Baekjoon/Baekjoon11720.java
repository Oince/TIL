//백준 11720번 숫자의 합
import java.io.*;
public class Baekjoon11720 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        String num = br.readLine();
        br.close();
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += Character.getNumericValue(num.charAt(i));
        }
        bw.write(Integer.toString(sum));
        bw.flush();
        bw.close();
    }
}
