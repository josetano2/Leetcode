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

    priority_queue<int> q;
    int kth;

    int kthSmallest(TreeNode* root, int k) {    
        kth = k;
        dfs(root);
        return q.top();
    }

    void dfs(TreeNode* curr){
        if(!curr) return;
        q.push(curr->val);

        if(q.size() > kth){
            q.pop();
        }
        
        dfs(curr->left);
        dfs(curr->right);
    }
};