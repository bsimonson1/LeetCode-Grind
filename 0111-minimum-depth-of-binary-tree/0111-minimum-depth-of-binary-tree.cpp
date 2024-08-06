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
    void finder(TreeNode* root, int& level)
    {
        if (root == nullptr)
        {
            return;
        }
        level++;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left == nullptr && curr->right == nullptr) return;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            level++;
        }
    }
    int minDepth(TreeNode* root) {
        int level = 0;
        finder(root, level);
        return level;
    }
};