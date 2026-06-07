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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> us;
        unordered_map<int, TreeNode*> um;

        for(int i = 0; i < descriptions.size(); i++) {
            us.insert(descriptions[i][1]);

            if (!um.count(descriptions[i][0])) um[descriptions[i][0]] = new TreeNode(descriptions[i][0]);
            if (!um.count(descriptions[i][1])) um[descriptions[i][1]] = new TreeNode(descriptions[i][1]);
            
            if(descriptions[i][2]) um[descriptions[i][0]]->left = um[descriptions[i][1]];
            else um[descriptions[i][0]]->right = um[descriptions[i][1]];
        }

        int root = -1;
        for(int i = 0; i < descriptions.size(); i++) {
            if(!us.count(descriptions[i][0])) {
                root = descriptions[i][0];
                break;
            }
        }

        return um[root];
    }
};