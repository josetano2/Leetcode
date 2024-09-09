class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (auto x : stones) {
            pq.push(x);
        }

        int x = 0, y = 0;
        while (!pq.empty()) {
            x = pq.top();
            pq.pop();

            if (pq.empty()) {
                return x;
            }

            y = pq.top();
            pq.pop();

            pq.push(x - y);
        }

        return -1;
    }
};