class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, long long> um;
        for(auto& t : time) um[t % 60]++;

        long long ans = 0;
        ans += (um[0] * (um[0] - 1) / 2) + (um[30] * (um[30] - 1) / 2);
        
        for (int i = 1; i <= 29; i++) ans += um[i] * um[60 - i];

        return ans;
    }
};