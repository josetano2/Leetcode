class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        if (!root) {
            return {};
        }

        vector<int> ans;
        queue<TreeNode*> q;

        int threshold = 2, howMuchChildren = 0;
        q.push(root);

        TreeNode* lastSavedNode = root;
        ans.push_back(root->val);

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (temp->left) {
                q.push(temp->left);
                howMuchChildren++;
                lastSavedNode = temp->left;
            } else {
                threshold--;
            }

            if (temp->right) {
                q.push(temp->right);
                howMuchChildren++;
                lastSavedNode = temp->right;
            } else {
                threshold--;
            }

            if (threshold == howMuchChildren) {
                if (lastSavedNode && lastSavedNode != root) {
                    ans.push_back(lastSavedNode->val);
                }
                lastSavedNode = nullptr;

                threshold *= 2;
                howMuchChildren = 0;
            }
        }

        return ans;
    }
};