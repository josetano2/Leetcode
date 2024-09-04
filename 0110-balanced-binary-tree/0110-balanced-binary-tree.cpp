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
    bool isBalanced(TreeNode* root) {
    
        int height = dfs(root);

        cout << "height: " << height << endl;
        
        return height == -1 ? false : true;
    }   

    int dfs(TreeNode* curr){

        if(!curr){
            return 0;
        }

        int left = dfs(curr->left);
        int right = dfs(curr->right);

        cout << left << " " << right << endl;

        if(abs(left - right) > 1){
            return -1;
        }

        return min(left, right) == -1 ? -1 : 1 + max(left, right);
    }
};