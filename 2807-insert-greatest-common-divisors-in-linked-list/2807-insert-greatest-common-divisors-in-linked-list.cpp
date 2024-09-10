class Solution {

private:
    int gcd(int a, int b) {
        if (a == 0) {
            return b;
        }

        if (b == 0) {
            return a;
        }

        if (a == b) {
            return a;
        }

        if (a > b) {
            return gcd(a - b, b);
        }

        return gcd(a, b - a);
    }

public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        ListNode* curr = head;

        while (curr) {
            ListNode* nextCurr = curr->next;
            if (nextCurr) {

                ListNode* nn = new ListNode(gcd(curr->val, nextCurr->val));
                cout << curr->val << endl;
                curr->next = nn;
                nn->next = nextCurr;

                curr = nextCurr;
            }
            curr = nextCurr;
        }

        return head;
    }
};