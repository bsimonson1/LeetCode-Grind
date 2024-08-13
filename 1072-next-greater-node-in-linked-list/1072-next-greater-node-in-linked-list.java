/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[] nextLargerNodes(ListNode head) {
        Stack<Integer> st = new Stack<>();
        ArrayList<Integer> res = new ArrayList<>();
        while (head != null)
        {
            res.add(head.val);
            head = head.next;
        }
        int n = res.size();
        for (int i = n - 1; i >= 0; i--)
        {
            int temp = res.get(i);
            while (!st.empty() && st.peek() <= temp)
            {
                st.pop();
            }
            if (st.empty())
            {
                res.set(i, 0);
            }
            else
            {
                res.set(i, st.peek());
            }
            st.push(temp);
        }
        int[] fin = new int[n];
        for (int i = 0; i < n; i++)
        {
            fin[i] = res.get(i);
        }
        return fin;
    }
}