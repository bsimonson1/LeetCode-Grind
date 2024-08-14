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
    public ListNode removeZeroSumSublists(ListNode head) {
        ArrayList<Integer> vals = new ArrayList<>();
        ListNode dummy = head;
        if (dummy == null)
        {
            return dummy;
        }
        while (dummy != null)
        {
            vals.add(dummy.val);
            dummy = dummy.next;
        }
        int i = 0;
        int j = 0;
        ArrayList<Integer> zeroSum = new ArrayList<>();
        boolean zero = false;
        int n = vals.size();
        int sum = 0;
        for (i = 0; i < n; i++)
        {
            sum += vals.get(i);
            if (sum == 0)
            {
                continue;
            }
            for (j = i + 1; j < n; j++)
            {
                sum += vals.get(j);
                if (sum == 0)
                {
                    i = j;
                    zero = true;
                    break;
                }
            }
            if (!zero)
            {
                zeroSum.add(vals.get(i));
            }
            sum = 0;
            zero = false;
        }
        ListNode fin = new ListNode();
        ListNode copy = fin;
        int count = 0;
        int l = zeroSum.size();
        while (count < l)
        {
            ListNode temp = new ListNode(zeroSum.get(count));
            copy.next = temp;
            copy = copy.next;
            count++;
        }
        return fin.next;
    }
}