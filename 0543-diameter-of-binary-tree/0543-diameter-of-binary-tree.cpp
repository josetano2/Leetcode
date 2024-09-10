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
    int diameterOfBinaryTree(TreeNode* root) {
        int heightLeft = 0, heightRight = 0;

        if(root->left) heightLeft = height(root->left);
        if(root->right) heightRight = height(root->right);

        return heightLeft + heightRight;
    }

    int height(TreeNode* curr){
        if(!curr){
            return 0;
        }
        return 1 + max(height(curr->left), height(curr->right));
    }
};