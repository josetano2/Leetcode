/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* curr = head;
        unordered_map<ListNode*, bool> uMap;
        
        while(curr != NULL){
            cout << curr->val << endl;
            if(uMap.find(curr) == uMap.end()){
                uMap[curr] = true;
            }
            else{
                return true;
            }
            curr = curr->next;
            
        }

        return false;
    }
};