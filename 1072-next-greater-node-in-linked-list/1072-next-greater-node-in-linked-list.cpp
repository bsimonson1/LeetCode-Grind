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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* mover = head;
        std::vector<int> largerNodes;
        bool notFound = true;
        while (mover != NULL)
        {
            ListNode* temp = mover->next;
            while (temp != NULL)
            {
                if (temp->val > mover->val)
                {
                    notFound = false;
                    largerNodes.push_back(temp->val);
                    break;
                }
                temp = temp->next;
            }
            if (notFound)
            {
                largerNodes.push_back(0);
            }
            notFound = true;
            mover = mover->next;
        }
        return largerNodes;
    }
};