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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = head;
        std::vector<int> vals;
        if (!head)
        {
            ListNode* ret = NULL;
            return ret;
        }
        while (dummy != NULL)
        {
            vals.push_back(dummy->val);
            dummy = dummy->next;
        }
        int sum = 0;
        int n = vals.size();
        bool zero = false;
        std::vector<int> nonZeroSum;
        int i = 0;
        int j = 0;
        for (i = 0; i < n; i++)
        {
            sum += vals[i];
            if (sum == 0)
            {
                continue;
            }
            for (j = i + 1; j < n; j++)
            {
                sum += vals[j];
                if (sum == 0)
                {
                    i = j;
                    zero = true;
                    break;
                }
            }
            if (!zero)
            {
                nonZeroSum.push_back(vals[i]);
            }
            zero = false;
            sum = 0;
        }
        int l = nonZeroSum.size();
        int count = 0;
        ListNode* fin = new ListNode();
        ListNode* copy = fin;
        while (count < l)
        {
            ListNode* builder = new ListNode(nonZeroSum[count]);
            count++;
            copy->next = builder;
            copy = copy->next;
        }
        return fin->next;
    }
};