class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto x : costs) pq.push(x);

        int ans = 0;
        while (!pq.empty()) {
            int curr = pq.top();
            pq.pop();
            if(coins < curr) break;
            ans++; coins -= curr;

        }

        return ans;
    }
};