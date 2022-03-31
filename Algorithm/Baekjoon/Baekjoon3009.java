//백준 3009번 네 번쨰 점
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class Baekjoon3009 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] point1 = br.readLine().split(" ");
        String[] point2 = br.readLine().split(" ");
        String[] point3 = br.readLine().split(" ");

        if(point1[0].equals(point2[0])){
            System.out.print(point3[0]);
        }
        else if(point2[0].equals(point3[0])){
            System.out.print(point1[0]);
        }
        else {
            System.out.print(point2[0]);
        }

        System.out.print(" ");

        if(point1[1].equals(point2[1])){
            System.out.print(point3[1]);
        }
        else if(point2[1].equals(point3[1])){
            System.out.print(point1[1]);
        }
        else {
            System.out.print(point2[1]);
        }
    }
}