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
    public ListNode middleNode(ListNode head) {
        ListNode first = head;
        ListNode last = head;
        int count = 0;
        while (first != null)
        {
            count++;
            first = first.next;
        }
        count /= 2;
        for (int i = 0; i < count; i++)
        {
            last = last.next;
        }
        return last;
    }
}