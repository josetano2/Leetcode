
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        queue<TreeNode*> q;
        vector<vector<int>> ans;

        if(!root){
            return ans;
        }

        q.push(root);
        int threshold = 2;

        int howMuchChildren = 0, currIdx = 0;

        while(!q.empty()){

            TreeNode* temp = q.front();
            q.pop();

            cout << temp->val << " ";

            if(ans.size() == currIdx){
                ans.push_back(vector<int>{temp->val});
            }
            else{
                ans[currIdx].push_back(temp->val);
            }

            if(temp->left){
                q.push(temp->left);
                howMuchChildren++;
            }
            else{
                threshold--;
            }

            if(temp->right){
                q.push(temp->right);
                howMuchChildren++;
            }
            else{
                threshold--;
            }

            if(threshold == howMuchChildren){
                threshold *= 2;
                howMuchChildren = 0;
                currIdx++;
            }
        }

        return ans;
        
    }
};