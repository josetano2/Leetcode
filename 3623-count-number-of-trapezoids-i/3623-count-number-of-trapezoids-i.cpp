class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, vector<int>> freq;
        long long int MOD = 1e09 + 7;

        for (auto& z : points) freq[z[1]].push_back(z[0]);

        vector<pair<int, int>> horizontals;

        for (auto& f : freq) {
            if (f.second.size() >= 2) {
                horizontals.push_back({ f.first, f.second.size() });
            }
        }
        long long sum = 0, squareSum = 0;
        for(int i = 0; i < horizontals.size(); i++) {
            int len = horizontals[i].second;

            long long way = (len % MOD * (len % MOD - 1)) / 2;
            sum += way;
            squareSum += way * way;
        }  
        return ((sum * sum - squareSum) / 2) % MOD;
    }
};