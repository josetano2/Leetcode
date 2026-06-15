/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* curr = head;

        int len = 0;
        while(curr) {
            curr = curr->next;
            len++;
        }
        
        if(len == 1) return nullptr;
        if(len == 2) {
            head->next = nullptr;
            return head;
        }

        len /= 2;  

        int i = 0;
        ListNode* newHead = head;
        curr = newHead;
        while(curr) {
            if(i + 1 == len) {
                ListNode* nx = curr->next;
                curr->next = nx->next; 
                nx = nullptr;
            }
            else{
                curr = curr->next;
            }
            i++;
        }
        return newHead;
    }
};