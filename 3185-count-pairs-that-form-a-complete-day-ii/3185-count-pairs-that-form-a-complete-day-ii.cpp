class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, long long> um;
        for(auto& h : hours) um[h % 24]++;

        long long ans = 0;
        ans += (um[0] * (um[0] - 1) / 2) + (um[12] * (um[12] - 1) / 2);
        
        for (int i = 1; i <= 11; i++) ans += um[i] * um[24 - i];

        return ans;
    }
};