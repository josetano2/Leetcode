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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int temp = l1->val + l2->val;
        int res = (l1->val + l2->val) / 10;
        temp = temp % 10;
        ListNode* head = new ListNode(temp);

        l1 = l1->next;
        l2 = l2->next;

        ListNode* curr = head;

        while(l1 && l2){
            temp = l1->val + l2->val + res;
            res = temp / 10;
            temp = temp % 10;

            ListNode* nn = new ListNode(temp);
            curr->next = nn;
            curr = curr->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            temp = l1->val + res;
             res = temp / 10;
            temp = temp % 10;

            ListNode* nn = new ListNode(temp);
            curr->next = nn;
            curr = curr->next;

            l1 = l1->next;
        }

        while(l2){
            temp = l2->val + res;
            res = temp / 10;
            temp = temp % 10;

            ListNode* nn = new ListNode(temp);
            curr->next = nn;
            curr = curr->next;

            l2 = l2->next;
        }

        if(res != 0){
            ListNode* nn = new ListNode(res);
            curr->next = nn;
        }

        return head;
    }
};