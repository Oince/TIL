// https://school.programmers.co.kr/learn/courses/30/lessons/389478
public class Programmers389478 {
    public static void main(String[] args) {
      Programmers389478 programmers389478 = new Programmers389478();
      int solution = programmers389478.solution(13, 3, 6);
      System.out.println(solution);
    }

  //n = 상자 총 개수, w = 가로 폭, num = 꺼내려는 상자 번호
  public int solution(int n, int w, int num) {
    //꺼내야 하는 상자의 총 개수 리턴
    num--;
    n--;

    int nCol = 0;
    int numCol = 0;
    int numRow = num / w;
    int maxRow = n / w;

    int answer = maxRow - numRow + 1;

    if (numRow % 2 == 0) {
      numCol = num % w;
    } else {
      numCol = w - 1 - (num % w);
    }

    if (maxRow % 2 == 0) {
      nCol = n % w;
      if (numCol > nCol) {
        answer--;
      }
    } else {
      nCol = w - 1 - (n % w);
      if (numCol < nCol) {
        answer--;
      }
    }

    return answer;
  }
}