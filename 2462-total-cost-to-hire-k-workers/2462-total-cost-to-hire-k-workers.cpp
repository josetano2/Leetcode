class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        int l = 0, r = costs.size() - 1;
        for(int i = 0; i < candidates; i++) {
            pq.push({costs[i], i});
            l++;
        }
        for(int i = costs.size() - 1; i > r - candidates; i--) {
            if(l > r) break;
            pq.push({costs[i], i});
            r--;
        }

        long long ans = 0;
        while(k--) {
            auto [cost, i] = pq.top();
            pq.pop();

            ans += cost;
            if(i < l && l <= r) {
                pq.push({costs[l], l}); l++;
            }
            else if(i > r && l <= r) {
                pq.push({costs[r], r}); r--;
            }
        }

        return ans;
    }
};