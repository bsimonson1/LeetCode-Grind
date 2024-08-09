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
 #include <iostream>
class Solution {
public:
    void recur(TreeNode* root, std::vector<int>& vals)
    {
        if (root != NULL)
        {
            vals.push_back(root->val);
            recur(root->left, vals);
            recur(root->right, vals);
        }
    }
    // bool recur(TreeNode* root, int k, std::set<int>& vals)
    // {
    //     if (root == NULL)
    //     {
    //         return false;
    //     }
    //     if (vals.count(k - root->val))
    //     {
    //         return true;
    //     }
    //     vals.insert(root->val);
        
    //     return recur(root->left, k, vals) || recur(root->right, k, vals);
    // }
    bool findTarget(TreeNode* root, int k) {
        // std::set<int> vals;
        // return recur(root, k, vals);
        std::vector<int> vals;
        recur(root, vals);
        for (int i = 0; i < vals.size() - 1; i++)
        {
            for (int j = i + 1; j < vals.size(); j++)
            {
                if (vals[i] + vals[j] == k)
                {
                    return true;
                }
            }
        }
        return false;
    }
};