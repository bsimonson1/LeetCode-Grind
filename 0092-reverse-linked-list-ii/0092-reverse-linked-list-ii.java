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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;

        for (int i = 1; i < left; i++)
        {
            prev = prev.next;
        }

        ListNode next = prev.next;
        ListNode reverse = next;
        ListNode curr = null; 
        for (int i = left; i <= right; i++)
        {
            ListNode temp = next;
            next = next.next;
            temp.next = curr;
            curr = temp;
        }
        prev.next = curr;
        reverse.next = next;
        return dummy.next;
    }
}