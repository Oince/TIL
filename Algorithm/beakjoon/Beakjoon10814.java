//https://www.acmicpc.net/problem/10814
//백준 10814번 나이순 정렬

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Beakjoon10814 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        Member[] members = new Member[n];

        for (int i = 0; i < members.length; i++) {
            st = new StringTokenizer(br.readLine());
            Member member = new Member(Integer.parseInt(st.nextToken()), st.nextToken());
            members[i] = member;
        }

        Arrays.sort(members);

        for (Member member : members) {
            bw.write(member.getAge() + " " + member.getName() + "\n");
        }
        bw.flush();
        bw.close();
    }

    //회원의 정보를 담을 클래스
    static class Member implements Comparable<Member>{
        private final int age;
        private final String name;

        public Member(int age, String name) {
            this.age = age;
            this.name = name;
        }

        public int getAge() {
            return age;
        }

        public String getName() {
            return name;
        }

        //age를 기준으로 정렬
        @Override
        public int compareTo(Member o) {
            if (this.age > o.age) {
                return 1;
            } else if (this.age < o.age) {
                return -1;
            } else {
                return 0;
            }
        }
    }
}

