class Solution{
public:
    ListNode *reverseList(ListNode *head){

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL){
            ListNode* temp = curr;
            curr = curr->next;
            temp->next = prev;
            prev = temp;
        }

        return prev;

    }
};