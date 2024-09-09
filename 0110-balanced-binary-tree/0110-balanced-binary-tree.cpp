class Solution {
public:
    bool isBalanced(TreeNode* root) {
    
        int height = dfs(root);
        return height == -1 ? false : true;
    }   

    int dfs(TreeNode* curr){

        if(!curr){
            return 0;
        }

        int left = dfs(curr->left);
        int right = dfs(curr->right);
        
        if(abs(left - right) > 1){
            return -1;
        }

        return min(left, right) == -1 ? -1 : 1 + max(left, right);
    }
};