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
    ListNode* removeNodes(ListNode* head) {
        if(head == nullptr) return nullptr;


        stack<int> stk;

        ListNode* curr = head;
        while(curr != nullptr) {
            if(stk.empty()) {
                stk.push(curr->val);
            }
            else {
                if(curr->val > stk.top()) {
                    while(!stk.empty() && curr->val > stk.top()) {
                        stk.pop();
                    }
                }
                stk.push(curr->val);
            }
            curr = curr->next;
        }

        stack<int> temp = stk;
        vector<int> rev;
        while (!stk.empty()) {
            rev.push_back(stk.top());
            stk.pop();
        }
        reverse(rev.begin(), rev.end());

        ListNode* ans = new ListNode(0);
        ListNode* tail = ans;

        for (int x : rev) {
            tail->next = new ListNode(x);
            tail = tail->next;
        }
        ans = ans->next;
        return ans;
    }
};