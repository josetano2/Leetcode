class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> q;

public:
    KthLargest(int k, vector<int>& nums) {
        for (auto x : nums) {
            if (q.size() < k) {
                q.push(x);
            } else {
                addToHeap(x);
            }
        }
    }

    void addToHeap(int val) {
        if (q.top() <= val) {
            q.pop();
            q.push(val);
        }
    }

    int add(int val) {
        addToHeap(val);
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */