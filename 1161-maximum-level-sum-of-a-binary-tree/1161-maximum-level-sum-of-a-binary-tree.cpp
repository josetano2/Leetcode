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
    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        int currMax = INT_MIN, level = 0, ans = INT_MIN;

        while(!q.empty()) {
            level++;
            int currSize = q.size(), currTot = 0;

            for(int i = 0; i < currSize; i++) {
                TreeNode* curr = q.front();
                currTot += curr->val;
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                q.pop();
            }

            if(currTot > currMax) {
                currMax = currTot;
                ans = level;
            }
        }

        return ans;
        
    }
};