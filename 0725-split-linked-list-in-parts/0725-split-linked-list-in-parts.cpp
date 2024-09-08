class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        ListNode* curr = head;
        vector<ListNode*> vectorNodes;

        int len = 0;

        while (curr) {
            curr = curr->next;
            len++;
        }

        int lenPerNode = len / k, counter = 1, currIdx = 0, extra = len % k;

        curr = head;
        ListNode* currNodeTracker;

        if (lenPerNode == 0) {

            counter = 0;

            while (curr) {
                ListNode* newNode = new ListNode(curr->val);
                vectorNodes.push_back(newNode);

                curr = curr->next;
            }

            for(int i = 0; i < k - len; i++){
                vectorNodes.push_back(nullptr);
                counter--;
            }

        }

        else {
            while (curr) {

                if (currIdx == vectorNodes.size()) {

                    vectorNodes.push_back(curr);
                    currNodeTracker = vectorNodes[currIdx];
                    curr = curr->next;

                    continue;
                }

                if (counter < lenPerNode ||
                    (extra > 0 && counter < lenPerNode + 1)) {
                    currNodeTracker->next = curr;
                    currNodeTracker = currNodeTracker->next;

                    counter++;
                    curr = curr->next;
                } else {
                    counter = 1;
                    currIdx++;
                    extra--;
                    currNodeTracker->next = nullptr;
                }
            }
        }

        return vectorNodes;
    }
};