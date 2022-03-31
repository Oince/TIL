//백준 1065번 한수
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class Baekjoon1065 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int input = Integer.parseInt(br.readLine());
        int count = 0;
        for(int i = 1; i <= input; i++) {
            if(isHansu(i))
                count++;
        }
        System.out.println(count);
    }
    
    static boolean isHansu(int num) {
        if(num < 100)
            return true;
        else if(num == 1000)
            return false;

        int[] arr = new int[3];
        int i = 0;

        while(num > 0) {
            arr[i++] = num % 10;
            num = num / 10;
        }

        if(arr[0] - arr[1] == arr[1] - arr[2])
            return true;
        else
            return false;
    }
}
