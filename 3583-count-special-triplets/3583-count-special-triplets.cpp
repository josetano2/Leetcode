class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        long long int MOD = 1e09 + 7;
        int n = nums.size();
        
        unordered_map<long long int, int> freq, prev;
        for (int x : nums) {
            freq[x % MOD]++;
        }
        
        long long int ans = 0;
        prev[nums[0] % MOD]++;
        
        for (int i = 1; i < n - 1; i++) {
            long long int half = nums[i] % MOD;
            long long int curr = half * 2;
            
            if ((curr ^ 1) == curr + 1 && freq.count(curr)) {
                long long int countBefore = prev[curr];
                long long int countAfter = freq[curr] - prev[curr] - (nums[i] == curr ? 1 : 0);
                
                ans = (ans + countBefore * countAfter) % MOD;
            }
            
            prev[nums[i] % MOD]++;
        }
        
        return ans;
    }
};