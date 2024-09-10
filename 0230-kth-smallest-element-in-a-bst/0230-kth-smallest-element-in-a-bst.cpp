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

    int kthSmallest(TreeNode* root, int k) {    

        queue<TreeNode*> nQ;
        nQ.push(root);

        while(!nQ.empty()){
            TreeNode* curr = nQ.front();
            nQ.pop();

            q.push(curr->val);
            if(q.size() > k){
                q.pop();
            }

            if(curr->left){
                nQ.push(curr->left);
            }
            if(curr->right){
                nQ.push(curr->right);
            }
        }

        return q.top();
    }
};