class Solution{
public:
    bool isSubPath(ListNode *head, TreeNode *root){
        return dfs(head, head, root);
    }

    bool dfs(ListNode* headList, ListNode* currList, TreeNode* curr){
        if(!currList){
            return true;
        }
        if(!curr){
            return false;
        }

        if(currList->val == curr->val){
            currList = currList->next;
        }
        else if(headList->val == curr->val){
            headList = headList->next;
        }
        else{
            currList = headList;
        }

        return dfs(headList, currList, curr->left) || dfs(headList, currList, curr->right);
    
    }
};