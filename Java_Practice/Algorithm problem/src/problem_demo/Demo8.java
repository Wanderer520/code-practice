package problem_demo;

import java.util.Arrays;
import java.util.Scanner;

// 洛谷 P1305 新二叉树：先序遍历
// 注意：提交洛谷时，类名必须改为 Main，并删除 package problem_demo; 这一行
public class Demo8 {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        char[] lchild = new char[256]; // 用字符当数组下标，256 覆盖所有 ASCII
        char[] rchild = new char[256];
        // 关键：char 数组默认值是 '\0'，必须全部初始化成 '*'，
        // 否则遍历到"只当过儿子、自己没单独一行"的叶子（如样例里的 m）时会无限递归
        Arrays.fill(lchild, '*');
        Arrays.fill(rchild, '*');
        boolean[] exist = new boolean[256]; // 出现过（是节点）
        boolean[] isChild = new boolean[256]; // 当过儿子（不可能是根）
        int size = cin.nextInt();
        for (int i = 0; i < size; i++) {
            // 关键：一行 3 个字符 = 节点名 + 左儿子 + 右儿子，要从同一个 token 里取
            String line = cin.next();
            char node = line.charAt(0);
            lchild[node] = line.charAt(1);
            rchild[node] = line.charAt(2);
            exist[node] = true;
            if (lchild[node] != '*')
                isChild[lchild[node]] = true;
            if (rchild[node] != '*')
                isChild[rchild[node]] = true;
        }
        // 根 = 出现过、但从未当过儿子的节点
        char root = '*';
        for (char c = 'a'; c <= 'z'; c++) {
            if (exist[c] && !isChild[c]) {
                root = c;
                break;
            }
        }
        PreOrder(lchild, rchild, root);
        System.out.println();
    }

    public static void PreOrder(char[] lchild, char[] rchild, char root) {
        if (root == '*')
            return;
        System.out.print(root);
        PreOrder(lchild, rchild, lchild[root]);
        PreOrder(lchild, rchild, rchild[root]);
    }
}
