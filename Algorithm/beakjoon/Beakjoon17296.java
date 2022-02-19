//https://www.acmicpc.net/problem/17298
//백준 17298번 오큰수
import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Beakjoon17296 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        Stack<Integer> stack = new Stack<>();
        int[] input = new int[n];

        //입력
        for (int i = 0; i < n; i++) {
            input[i] = Integer.parseInt(st.nextToken());
        }

        //결과 배열
        int[] result = new int[n];
        //제일 오른쪽은 항상 -1임
        result[n - 1] = -1;
        int i;

        //가장 오른쪽 수를 스택에 넣음
        stack.push(input[n - 1]);

        //오른쪽에서 두번째 수 부터 시작
        for (i = n - 2; i >= 0; i--) {

            //스택이 비어있는지 확인
            while (!stack.isEmpty()) {
                int item = stack.peek();

                //스택에서 제일 위에있는 수가 i번째 수보다 크면
                if (item > input[i]) {
                    //결과 배열에 넣음
                    result[i] = item;
                    break;
                } else {
                    //아니면 스택에서 수를 꺼냄
                    stack.pop();
                }
            }

            //위의 반복문을 돌았을 때 스택이 비어있다면 스택에 i번째 수보다 큰 수가 없다는 뜻
            //그러므로 결과 배열에 -1을 넣음
            if (stack.isEmpty()) {
                result[i] = -1;
            }

            //스택에 i번째 수를 넣음
            stack.push(input[i]);

        }

        //결과 출력
        for (int number : result) {
            bw.write(String.valueOf(number));
            bw.write(" ");
        }
        bw.flush();

    }
}