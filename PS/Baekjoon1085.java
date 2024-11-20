//백준 1085번 직사각형에서 탈출
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
public class Baekjoon1085 {
   public static void main(String[] args) throws IOException{
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine());
      int x = Integer.parseInt(st.nextToken());
      int y = Integer.parseInt(st.nextToken());
      int w = Integer.parseInt(st.nextToken());
      int h = Integer.parseInt(st.nextToken());
      int distanceX = Math.min(y, h - y);
      int distanceY = Math.min(x, w - x);
      if(distanceX <= distanceY) {
         System.out.println(distanceX);
      }
      else {
         System.out.println(distanceY);
      }

   }
}
