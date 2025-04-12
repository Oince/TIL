//백준 1018번 체스판 다시 칠하기
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
public class Baekjoon1018 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        char[][] chessboard = new char[n][m];
        boolean flag;
        int count = 0, result = 64;

        for (int i = 0; i < n; i++) {
            chessboard[i] = br.readLine().toCharArray();
        }

        for (int i = 0; i <= n - 8; i++) {
            for (int j = 0; j <= m - 8; j++) {

                flag = chessboard[i][j] == 'W';
                count = 0;

                for (int k = i; k < i + 8; k++) {
                    for (int l = j; l < j + 8; l++) {
                        if ((chessboard[k][l] == 'W') != flag) {
                            count++;
                        }
                        flag = !flag;
                    }
                    flag = !flag;
                }
                count = Math.min(count, 64 - count);
                if (count < result) {
                    result = count;
                }

            }
        }
        System.out.println(result);
    }
}