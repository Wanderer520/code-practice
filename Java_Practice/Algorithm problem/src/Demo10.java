import java.util.Scanner;

public class Demo10 {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        String in = cin.next();
        String pre = cin.next();
        StringBuilder post = new StringBuilder();
        getPostOrder(pre, in, post);
        System.out.println(post.toString());
    }

    public static void getPostOrder(String pre, String in,StringBuilder post) {
        if (pre.length() == 0) {
            return;
        }
        char root = pre.charAt(0);
        int rootIndex = in.indexOf(root);
        getPostOrder(pre.substring(1, rootIndex + 1), in.substring(0, rootIndex), post);
        getPostOrder(pre.substring(rootIndex + 1), in.substring(rootIndex + 1), post);
        post.append(root);
        return;
    }
}
