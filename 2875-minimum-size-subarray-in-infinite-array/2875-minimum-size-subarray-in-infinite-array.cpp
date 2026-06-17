class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long sum = 0, n = nums.size();
        for(auto& x : nums) sum += x;

        long long tc = target / sum, rem = target % sum;
        if(rem == 0) return tc * n;
        
        nums.insert(nums.begin(), nums.begin(), nums.end());

        int len = INT_MAX, l = 0;
        long long curr = 0;

        for(int r = 0; r < nums.size(); r++) {
            curr += nums[r];
            while(curr > rem) {
                curr -= nums[l];
                l++;
            }
            if(curr == rem) len = min(len, r - l + 1);
        }

        return len == INT_MAX ? -1 : tc * n + len;
    }
};