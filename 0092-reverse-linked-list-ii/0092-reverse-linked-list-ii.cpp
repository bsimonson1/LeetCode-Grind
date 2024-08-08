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
 #include <iostream>
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        for (int i = 1; i < left; i++)
        {
            prev = prev->next;
        }

        ListNode* copy = prev->next;
        ListNode* reverse_tail = copy;
        ListNode* next = NULL;
        for (int i = left; i <= right; i++)
        {    
            ListNode* temp = copy;
            copy = copy->next;
            temp->next = next;
            next = temp;
        }
        prev->next = next;
        reverse_tail->next = copy;

        return dummy->next;
    }
};