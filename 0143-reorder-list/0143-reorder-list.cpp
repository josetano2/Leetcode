
class Solution{
public:
    void reorderList(ListNode* head) {

        if(!head || !head->next || !head->next->next) {
            return;
        }

        stack<ListNode*> stk;

        ListNode* curr = head;
        int counter = 0;
        while(curr){
            counter++;
            stk.push(curr);
            curr = curr->next;
        }

        curr = head;
        for(int i = 0; i < counter/2; i++){
            ListNode* temp = stk.top();
            stk.pop();
            temp->next = curr->next;
            curr->next = temp;

            curr = curr->next->next;
        }

        curr->next = nullptr;

    }

};