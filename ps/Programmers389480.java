import java.util.*;

// https://school.programmers.co.kr/learn/courses/30/lessons/389480
public class Programmers389480 {

  int[][] info;
  int[][] memo;
  int n;
  int m;
  final int MAX = 130;
  int ans = MAX;

  public static void main(String[] args) {
    int[][] info = {{3, 3}, {3, 3}};
    int n = 7;
    int m = 1;
    Programmers389480 programmers389480 = new Programmers389480();
    int answer = programmers389480.solution(info, n, m);
    System.out.println(answer);
  }

  public int solution(int[][] info, int n, int m) {
    this.info = info;
    this.n = n;
    this.m = m;

    int maxA = 0;
    for (int[] depth : info) {
      maxA += depth[0];
    }
    memo = new int[info.length + 1][maxA + 1];
    for (int[] me : memo) {
      Arrays.fill(me, MAX);
    }

    dfs(0, 0, 0);
    if (ans >= n) {
      return -1;
    }
    return ans;
  }

  public void dfs(int depth, int a, int b) {
    if (a >= n || b >= m) {
      return;
    }
    if (memo[depth][a] <= b) {
      return;
    }
    memo[depth][a] = b;

    if (depth >= info.length) {
      ans = Math.min(a, ans);
      return;
    }

    int aNext = a + info[depth][0];
    int bNext = b + info[depth][1];

    dfs(depth + 1, aNext, b);
    dfs(depth + 1, a, bNext);
  }
}
