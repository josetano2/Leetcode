class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        stack<ListNode*> stk;

        ListNode* curr = head;

        while(curr){
            stk.push(curr);
            curr = curr->next;
        }
        int counter = 1;

        ListNode* newHead = NULL;
        ListNode* newTail = NULL;
        while(!stk.empty()){
            if(counter != n){
                ListNode* newNode = new ListNode(stk.top()->val, nullptr);
                if(!newHead){
                    newHead = newNode;
                    newTail = newNode;
                }
                else{
                    newTail->next = newNode;
                    newTail = newNode;
                }
            }
            stk.pop();
            counter++;
        }

        

        return reverseList(newHead);

    }

    ListNode *reverseList(ListNode *head){

        ListNode* headTemp = head;
        ListNode* curr = headTemp;
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