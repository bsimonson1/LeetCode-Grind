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
        
        // first we want to iterate through to the a point
        for (int i = 0; i < a - 1; i++)
        {
            node_a = node_a->next;
        }
        // now we want to iterate through list2 to get to the point where we reconnect to list1
        ListNode* connection = list2;
        while (connection->next != NULL)
        {
            connection = connection->next;
        }
        // now we want to find the b point
        for (int i = 0; i <= b; i++)
        {
            node_b = node_b->next;
        }
        // now we are ready to reconect list2 next pointer to the end of list1 reference
        connection->next = node_b;
        // now that the list2 reference connection points back to the end of list1, we can connect nodea to it
        node_a->next = list2; //note, we want the head of list2 not the connection node which should be the last node of a
        // return list1 (the head) since all the references are properly aligned
        return list1;
    }
};