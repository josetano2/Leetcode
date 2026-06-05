class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<int> stk;
        ListNode* curr = head;
        while(curr != nullptr) {
            while(!stk.empty() && curr->val > stk.top()) stk.pop();
            stk.push(curr->val);
            curr = curr->next;
        }

        ListNode* ans = nullptr;
        while (!stk.empty()) {
            ans = new ListNode(stk.top(), ans);
            stk.pop();
        }
        return ans;
    }
};