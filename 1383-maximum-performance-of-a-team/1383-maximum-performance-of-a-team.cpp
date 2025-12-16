class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency,
                       int k) {
        vector<pair<long long, long long>> combine;
        long long MOD = 1e09+7;
        for (int i = 0; i < n; i++)
            combine.push_back({speed[i], efficiency[i]});

        sort(combine.begin(), combine.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 if (a.second == b.second) {
                     return a.first > b.first;
                 }
                 return a.second > b.second;
             });

        long long speedSum = 0, performance = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < n; i++) {
            auto [s, e] = combine[i];

            pq.push(s);
            speedSum += s;
            if(pq.size() > k) {
                long long toRemove = pq.top();
                pq.pop();
                speedSum -= toRemove;
            }
            performance = max(performance, speedSum * e);

        }
        return performance % MOD;
    }
};