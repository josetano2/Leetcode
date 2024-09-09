class Solution {
public:

    bool flag = true;

    bool isSameTree(TreeNode* p, TreeNode* q) {
        dfs(p, q);
        return flag; 
    }

    void dfs(TreeNode* p, TreeNode* q) {

        if((p && !q) || (!p && q)){
            flag = false;
            return;
        }

        if (!p || !q) {
            return;
        }
        else{
            if(p->val != q->val){
                flag = false;
                return;
            }
        }

        cout << p->val << " " << q->val << endl;
        dfs(p->left, q->left);
        dfs(p->right, q->right);
    }
};