package problem_demo;

import java.io.*;
import java.util.*;

public class Demo9 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] l = new int[n+1];
        int[] r = new int[n+1];
        for(int i=1;i<=n;i++){
            st = new StringTokenizer(br.readLine());
            l[i] = Integer.parseInt(st.nextToken());
            r[i] = Integer.parseInt(st.nextToken());
        }
        System.out.println(getDepth(l, r));
    }

    public static int getDepth(int[] l,int[] r){
        int[] queue = new int[l.length];//数组队列
        int front = 0; //队头
        int rear = 0;//队尾
        queue[rear++] = 1;
        int depth = 0;
        while(front < rear){
            int levelSize = rear - front;
            depth++;
            for(int i = 0; i < levelSize ;i++){
                int cur = queue[front++];
                if(l[cur]!=0) queue[rear++] = l[cur];
                if(r[cur]!=0) queue[rear++] = r[cur];
            }
        }
        return depth;
    }
}
