/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recur(TreeNode* root, std::map<int, int>& mp)
    {
        if (root != NULL)
        {
            mp[root->val]++;
            recur(root->left, mp);
            recur(root->right, mp);
        }
    }
    vector<int> findMode(TreeNode* root) {
        std::map<int, int> mp;
        recur(root, mp);
        std::vector<int> ret;
        int max = 0;
        for (auto& i: mp)
        {
            if (i.second > max)
            {
                max = i.second;
            }
        }
        for (auto& i: mp)
        {
            if (i.second == max)
            {
                ret.push_back(i.first);
            }
        }
        return ret;
    }
};