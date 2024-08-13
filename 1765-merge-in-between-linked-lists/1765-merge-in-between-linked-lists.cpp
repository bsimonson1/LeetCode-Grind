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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) { 
        ListNode* node_a = list1;      
        ListNode* node_b = list1;
        for (int i = 0; i < b; i++)
        {
            if (i < a-1)
            {
                node_a = node_a->next;

            }
            node_b = node_b->next;
        }
        // now node a has everything from the beginning up until the ath node, and the list2
        ListNode* connection = list2;
        while (connection->next != NULL)
        {
            connection = connection->next;
        }
        // nodebs next pointer is ready to point at the end of the list
        connection->next = node_b->next;
        node_a->next = list2;
        return list1;
    }
};