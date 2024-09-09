class Solution{
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        queue<TreeNode*> queue;

        queue.push(root);
        bool isSame = false;

        while(!queue.empty()){
            
            TreeNode* temp = queue.front();
            queue.pop();

            if(temp->val == subRoot->val){
                isSame = isSameTree(temp, subRoot);
                if(isSame){
                    break;
                }
            }

            if(temp->left){
                queue.push(temp->left);
            }
            if(temp->right){
                queue.push(temp->right);
            }
        }
        
        return isSame;
    }

    bool isSameTree(TreeNode* p, TreeNode* q){

        if((p && !q) || (!p && q)){
            return false;
        }

        if(!p && !q){
            return true;
        }
        
        if(p && q && p->val == q->val){
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }

        return false;
    }
};