//https://www.acmicpc.net/problem/1259
//백준 1259번 팰린드롬 수
import java.io.*;

public class Baekjoon1259 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String input;
        char[] array;
        int i;
        boolean flag = true;

        while (true) {
            input = br.readLine();
            if (input.equals("0")) {
                break;
            }

            array = input.toCharArray();

            for (i = 0; i < array.length / 2; i++) {
                if (array[i] != array[array.length - 1 - i]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                bw.write("yes\n");
            } else {
                bw.write("no\n");
            }

            flag = true;

        }

        bw.flush();
        bw.close();

    }
}