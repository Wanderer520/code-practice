package problem_demo;

import java.util.Deque;
import java.util.Scanner;

public class Demo7 {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        int m = cin.nextInt();
        Deque<Integer> deque = new java.util.ArrayDeque<>();
        for (int i = 0; i < n; i++)
            deque.offer(i + 1);
        while(n>0){
            int p = m;
            while(p>1){
                p--;
                deque.offer(deque.poll());
            }
            System.out.print(deque.poll()+" ");
            n--;
        }
    }
}
