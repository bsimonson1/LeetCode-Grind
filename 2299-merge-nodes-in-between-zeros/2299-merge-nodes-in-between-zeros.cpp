/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        int zero = 0;
        int sum = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* sums = dummy;
        while (head != NULL)
        {
            if (head->val == 0)
            {
                zero++;
            }
            if (zero > 0)
            {
                sum += head->val;
            }
            if (zero == 2) 
            {
                sums->next = new ListNode(sum);
                sums = sums->next;
                zero = 1; 
                sum = 0; // Reset sum
            }
        head = head->next; 
    }
    return dummy->next; 
    }
};