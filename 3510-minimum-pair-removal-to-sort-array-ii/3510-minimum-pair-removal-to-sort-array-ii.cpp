class Solution {
public:

    struct Node {
        long long val;
        int idx;
        Node* next;
        Node* prev;

        Node(long long v, int i) : val(v), idx(i), next(nullptr), prev(nullptr) {}
    };

    int minimumPairRemoval(vector<int>& nums) {

        if(nums.size() == 1) return 0;

        Node* head = new Node(nums[0], 0);
        Node* curr = head;

        int violations = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i - 1]) violations++;

            Node* nn = new Node(nums[i], i);
            curr->next = nn;
            nn->prev = curr;
            curr = nn;
        }

        set<pair<pair<long long, int>, Node*>> pairMinSumSet;
        curr = head;
        while(curr && curr->next) {
            pairMinSumSet.insert({{curr->val + curr->next->val, curr->idx}, curr});
            curr = curr->next;
        }

        int count = 0;
        while(violations > 0) {
            auto [diff, curr] = *pairMinSumSet.begin();
            Node* l = curr;
            Node* r = l->next;

            pairMinSumSet.erase({{diff.first, diff.second}, curr});

            int oldViolation = 0;
            if(l->prev && l->prev->val > l->val) oldViolation++;
            if(l->val > r->val) oldViolation++;
            if(r->next && r->val > r->next->val) oldViolation++;

            if(l->prev) pairMinSumSet.erase({{l->prev->val + l->val, l->prev->idx}, l->prev});
            if(r->next) pairMinSumSet.erase({{r->val + r->next->val, r->idx}, r});

            Node* nn = new Node(l->val + r->val, l->idx);
            nn->prev = l->prev;
            nn->next = r->next;
            
            if(nn->prev) nn->prev->next = nn;
            if(nn->next) nn->next->prev = nn;

            if(nn->prev) pairMinSumSet.insert({{nn->prev->val + nn->val, nn->prev->idx}, nn->prev});
            if(nn->next) pairMinSumSet.insert({{nn->val + nn->next->val, nn->idx}, nn});

            int newViolation = 0;
            if(nn->prev && nn->prev->val > nn->val) newViolation++;
            if(nn->next && nn->val > nn->next->val) newViolation++;

            violations = violations - oldViolation + newViolation;
            
            delete l;
            delete r;

            count++;
        }

        return count;
    }
};