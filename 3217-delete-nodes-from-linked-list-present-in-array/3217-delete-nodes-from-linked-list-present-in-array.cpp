class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        unordered_set<int> uSet;

        for (auto x : nums) {
            uSet.insert(x);
        }

        ListNode* curr = head;
        ListNode* lastSavedNode = NULL;

        while (curr != NULL) {
            if (uSet.find(curr->val) != uSet.end() && !lastSavedNode) {
                ListNode* temp = curr;
                ListNode* next = curr->next;

                temp->next = nullptr;
                curr = next;
                lastSavedNode = curr;

                if (head == temp) {
                    cout << head->val << endl;
                    head = curr;
                }

                temp = nullptr;

                continue;
            } else if (uSet.find(curr->val) != uSet.end() && lastSavedNode) {
     
                ListNode* temp = curr;
                ListNode* next = curr->next;

                temp->next = nullptr;

                lastSavedNode->next = next;
                if(uSet.find(curr->val) != uSet.end()){
                    lastSavedNode = curr;
                }
                curr = next;

                if (head == temp) {
                    head = curr;
                }

                temp = nullptr;

                continue;
            }

            else {
                lastSavedNode = curr;
                curr = curr->next;
            }
        }


        return head;
    }
};