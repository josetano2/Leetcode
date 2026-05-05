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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0) return head;
        ListNode* tempHead = head;

        int s = 0;
        while(tempHead != nullptr) {
            tempHead = tempHead->next;
            s++;
        }

        int count = k % s;
        if(count == 0) return head;
        int i = 0;

        ListNode* newHead = head;
        for(int i = 0; i < s - count - 1; i++) newHead = newHead->next;
        
        ListNode* actualHead = newHead->next;
        newHead->next = nullptr;

        ListNode* tail = actualHead;
        while(tail->next != nullptr) tail = tail->next;
        tail->next = head;

        return actualHead;
    }
};