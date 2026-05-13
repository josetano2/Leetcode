class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        
        vector<int> prefixSum(limit * 2 + 2, 0);
        int n = nums.size();
        for(int i = 0; i < n / 2; i++) {
            int a = min(nums[i], nums[n - i - 1]), b = max(nums[i], nums[n - i - 1]), diff = a + b;
                prefixSum[2] += 2;
                prefixSum[a + 1] -= 2;
            
                prefixSum[a + 1] += 1;
                prefixSum[a + b] -= 1;
            
                prefixSum[a + b + 1] += 1;
                prefixSum[b + limit + 1] -= 1;
            
                prefixSum[b + limit + 1] += 2;
                prefixSum[2 * limit + 1] -= 2;
        }

        int ans = INT_MAX, curr = 0;
        for(int i = 2; i <= 2 * limit; i++) {
            curr += prefixSum[i];
            ans = min(ans, curr);
        }
        return ans;
    }
};