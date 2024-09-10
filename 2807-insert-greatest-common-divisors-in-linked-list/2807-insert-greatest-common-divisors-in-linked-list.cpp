class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        ListNode* curr = head;

        while (curr) {
            ListNode* nextCurr = curr->next;
            if (nextCurr) {
                ListNode* nn = new ListNode(__gcd(curr->val, nextCurr->val));
                curr->next = nn;
                nn->next = nextCurr;
            }
            curr = nextCurr;
        }

        return head;
    }
};