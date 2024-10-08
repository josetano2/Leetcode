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
    int countNodes(TreeNode* root) {

        if(!root) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int count = 0;

        while(!q.empty()){
            TreeNode* temp = q.front();
            count++;
            q.pop();

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            
        }

        return count;
    }
};