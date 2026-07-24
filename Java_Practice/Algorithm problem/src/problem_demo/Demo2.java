package problem_demo;

public class Demo2 {
    public static void main(String[] args) {
        ListNode l1 = new ListNode(9);
        ListNode l2 = new ListNode(1);
        for (int i = 0; i < 9; i++) {
            ListNode node = new ListNode(9);
            node.next = l2.next;
            l2.next = node;
        }
        ListNode result = addTwoNumbers(l1, l2);
        while (result != null) {
            System.out.print(result.val + " ");
            result = result.next;
        }
    }

    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode p = head;
        int sum = 0;
        while (l1 != null || l2 != null) {
            if (l1 != null) {
                sum += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                sum += l2.val;
                l2 = l2.next;
            }
            p.next = new ListNode(sum % 10);
            p = p.next;
            sum /= 10;
        }
        if (sum == 1)
            p.next = new ListNode(1);
        return head.next;
    }
}
