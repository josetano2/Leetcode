/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* dfs(TreeNode* curr, TreeNode* p, TreeNode* q) {
        if(p->val < curr->val && q->val < curr->val) return dfs(curr->left, p, q);
        if(p->val > curr->val && q->val > curr->val) return dfs(curr->right, p, q);
        return curr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};