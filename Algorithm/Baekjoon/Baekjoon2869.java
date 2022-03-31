//백준 2869번 달팽이는 올라가고 싶다
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;
public class Baekjoon2869 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int v = Integer.parseInt(st.nextToken());
        int day = (int)Math.ceil((double)(v-b) / (a-b));
        bw.write(String.valueOf(day));
        bw.flush();
    }   
}
