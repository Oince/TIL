//백준 10845번 큐
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.StringTokenizer;
public class Baekjoon10845 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        String command;
        int number;
        Queue queue = new Queue();
        int n = Integer.parseInt(br.readLine());
        while(n > 0) {
            st = new StringTokenizer(br.readLine());
            command = st.nextToken();
            switch (command) {
                case "push":
                    number = Integer.parseInt(st.nextToken());
                    queue.push(number);
                    break;
                case "pop":
                    queue.pop();
                    break;
                case "size":
                    queue.size();
                    break;
                case "empty":
                    queue.empty();
                    break;
                case "front":
                    queue.front();
                    break;
                case "back":
                    queue.back();
                    break;
                default:
            }
            n--;
        }
    }
}

class Queue {

    private LinkedList<Integer> queue = new LinkedList<>();
    private BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public void push(int n) {
        queue.addLast(n);
    }

    public void pop() throws IOException{
        if(queue.isEmpty()) {
            bw.write("-1\n");
        }
        else {
            bw.write(String.valueOf(queue.removeFirst()) + "\n");
        }
        bw.flush();
    }
    
    public void size() throws IOException{
        bw.write(String.valueOf(queue.size()) + "\n");
        bw.flush();
    }

    public void empty() throws IOException{
        if(queue.isEmpty()) {
            bw.write("1\n");
        }
        else {
            bw.write("0\n");
        }
        bw.flush();
    }

    public void front() throws IOException{
        if(queue.isEmpty()) {
            bw.write("-1\n");
        }
        else {
            bw.write(String.valueOf(queue.getFirst()) + "\n");
        }
        bw.flush();
    }

    public void back() throws IOException{
        if(queue.isEmpty()) {
            bw.write("-1\n");
        }
        else {
            bw.write(String.valueOf(queue.getLast()) + "\n");
        }
        bw.flush();
    }
}