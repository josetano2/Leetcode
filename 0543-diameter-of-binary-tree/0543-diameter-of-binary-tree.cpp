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
    vector<int> ans;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);

        int diameter = -1;
        for(auto x : ans){
            diameter = max(diameter, x);
        }

        return diameter;
    }

    int countHeight(TreeNode* curr){
        int heightLeft = 0, heightRight = 0;

        if(curr->left) heightLeft = height(curr->left);
        if(curr->right) heightRight = height(curr->right);

        return heightLeft + heightRight;
    }

    void dfs(TreeNode* curr){
        if(!curr){
            return;
        }

        ans.push_back(countHeight(curr));
        dfs(curr->left);
        dfs(curr->right);
    }

    int height(TreeNode* curr){
        if(!curr){
            return 0;
        }
        return 1 + max(height(curr->left), height(curr->right));
    }
};