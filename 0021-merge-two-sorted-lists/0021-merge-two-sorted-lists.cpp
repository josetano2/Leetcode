class Solution{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2){
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(curr1 != NULL || curr2 != NULL){
            if(curr1 == NULL){
                pushTail(curr2->val, head, tail);
                curr2 = curr2->next;
            }
            else if(curr2 == NULL){
                pushTail(curr1->val, head, tail);
                curr1 = curr1->next;
            }
            else{
                if(curr1->val < curr2->val){
                    pushTail(curr1->val, head, tail);
                    curr1 = curr1->next;
                }
                else{
                    pushTail(curr2->val, head, tail);
                    curr2 = curr2->next;
                }
            }
        }

        return head;

    }

    void pushTail(int val, ListNode* &head, ListNode* &tail){
        ListNode* newNode = new ListNode(val, nullptr);

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        // cout << tail->val << endl;
    }
};
