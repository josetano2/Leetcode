class Solution {
public:
    // naive
    // ListNode* middleNode(ListNode* head) {

    //     int counter = 0;
    //     ListNode* curr = head;
    //     while(curr != NULL){
    //         curr = curr->next;
    //         counter++;
    //     }

    //     int half = counter / 2;
    //     counter = 0;
    //     curr = head;
    //     while(counter != half){
    //         curr = curr->next;
    //         counter++;
    //     }


    //     return curr;
    // }
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
