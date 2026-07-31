package problem_demo;

import java.util.Arrays;

public class Demo3 {
    public static void main(String[] args) {
        int[] stones = {2,7,4,1,8,1};
        System.out.println(lastStoneWeight(stones));
        System.out.println("中文");
    }

    public static int lastStoneWeight(int[] stones) {
        int n = stones.length;
        if(n==1)
            return stones[0];
        while(n > 2){
            Arrays.sort(stones);
            int a = stones[n-1];
            int b = stones[n-2];
            if(a==b) {
                n-=2;
                continue;
            }
            stones[n-2] = a - b;
            n--;
        }
        Arrays.sort(stones);
        if(n==2) {
            if (stones[0] == stones[1])
                return 0;
            else
                return stones[1] - stones[0];
        }
        return stones[0];
    }
}
