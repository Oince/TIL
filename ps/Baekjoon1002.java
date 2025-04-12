//백준 1002번 터렛
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
public class Baekjoon1002 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        StringTokenizer st;
        while(T > 0) {
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int r1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            int r2 = Integer.parseInt(st.nextToken());

            if(x1 == x2 && y1 == y2) {
                if(r1 == r2)
                    System.out.println("-1");
                else
                    System.out.println("0");
            }
            else {
                int distance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 -y2);
                if(distance < (r1 - r2) * (r1 - r2))
                    System.out.println("0");
                else if(distance == (r1 -r2) * (r1 -r2))
                    System.out.println("1");
                else if(distance > (r1 + r2) * (r1 + r2))
                    System.out.println("0");
                else if(distance == (r1 + r2) * (r1 + r2))
                    System.out.println("1");
                else
                    System.out.println("2");
            }
            T--;
        }
    }
}