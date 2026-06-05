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
                while(!stk.empty() && curr->val > stk.top()) stk.pop();
                stk.push(curr->val);
            }
            curr = curr->next;
        }

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