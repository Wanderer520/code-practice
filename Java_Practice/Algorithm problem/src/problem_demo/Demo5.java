package problem_demo;

import java.util.Deque;

public class Demo5 {
    public static void main(String[] args) {
        // 程序入口，当前示例中没有额外逻辑
    }

    /**
     * 判断给定字符串中的括号是否有效匹配。
     * 例如："()[]{}" 合法，"([)]" 非法。
     * 核心思路：使用栈来保存待匹配的左括号，遇到右括号时检查栈顶是否对应。
     */
    public boolean isValid(String s) {
        // 使用栈来存储左括号，栈顶元素表示最近出现的未匹配括号
        Deque<Character> stack = new java.util.ArrayDeque<>();

        // 依次遍历字符串中的每个字符
        for (char c : s.toCharArray()) {
            // 如果栈为空，说明当前字符一定是左括号，直接入栈
            if (stack.isEmpty()) {
                stack.push(c);
                continue;
            }

            // 查看栈顶元素，用于判断当前右括号是否匹配最近的左括号
            char a = stack.peek();

            // 遇到右小括号时，检查栈顶是否为左小括号
            if (c == ')') {
                if (a == '(') {
                    stack.pop(); // 匹配成功，出栈
                } else {
                    return false; // 不匹配直接返回 false
                }
            } else if (c == ']') { // 遇到右中括号
                if (a == '[') {
                    stack.pop();
                } else {
                    return false;
                }
            } else if (c == '}') { // 遇到右大括号
                if (a == '{') {
                    stack.pop();
                } else {
                    return false;
                }
            } else {
                // 其他字符（左括号）压栈等待后续匹配
                stack.push(c);
            }
        }

        // 遍历结束后，如果栈为空，说明所有括号都已匹配成功
        if (stack.isEmpty()) {
            return true;
        }
        return false;
    }
}
