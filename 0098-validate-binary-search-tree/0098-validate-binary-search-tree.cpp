/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool flag = true;
    void dfs(TreeNode* curr, long minVal, long maxVal) {
        if (!curr) return;
        if (curr->val <= minVal || curr->val >= maxVal) flag = false;

        dfs(curr->left, minVal, curr->val);
        dfs(curr->right, curr->val, maxVal);
    }
    bool isValidBST(TreeNode* root) {
        if (!root->left && !root->right) return true;
        dfs(root, LONG_MIN, LONG_MAX);
        return flag;
    }
};