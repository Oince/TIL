//백준3053번 택시 기하학
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class Baekjoon3053 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int r = Integer.parseInt(br.readLine());
        System.out.println(Math.PI * r * r);
        System.out.println(r * r * 2);
    }
}
  