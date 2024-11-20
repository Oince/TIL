//백준 4673번 셀프넘버
public class Baekjoon4673 {
    public static void main(String[] args) {
        boolean[] number = new boolean[10000];
        int tmp;
        for(int i = 1; i< number.length; i++) {
            tmp = d(i);
            if(tmp >= number.length){
                continue;
            }
            number[tmp] = true;
        }
        for(int i = 1; i < number.length; i++) {
            if(number[i] == false){
                System.out.println(i);
            }
        }
    }

    static int d(int n) {
        int result = n;
        while(n > 0) {
            result = result + n % 10;
            n = n / 10;
        }
        return result;
    }
}
