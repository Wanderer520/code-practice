package problem_demo;

import java.util.Deque;
import java.util.Scanner;

public class Demo6 {
    public static void main(String args[]) throws Exception {
        Scanner cin=new Scanner(System.in);
        String s = cin.next();
        if(isValid(s))
            System.out.println("YES");
        else
            System.out.println("NO");
    }
    public static boolean isValid(String s){
        Deque<Character> stack = new java.util.ArrayDeque<>();
        for(char c : s.toCharArray()){
            if(c=='@')
                break;
            if(c == '(' || c==')'){
                if(stack.isEmpty()) {
                    if (c == '(') {
                        stack.push(c);
                        continue;
                    }else
                        return false;
                }
                char a = stack.peek();
                if(c == ')'){
                    if(a == '(')
                        stack.pop();
                    else
                        return false;
                }else
                    stack.push(c);
            }
        }
        if(stack.isEmpty())
            return true;
        else
            return false;
    }
}
