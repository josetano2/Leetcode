class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        
        long long ans = INT_MIN, sum = 0;

        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++) {
            if(i + 1 >= k) {
                freq[nums[i]]++;
                sum += nums[i];

                // check total distinct
                if(freq.size() >= m) ans = max(sum, ans);
            
                freq[nums[i - k + 1]]--;
                if(freq[nums[i - k + 1]] == 0) freq.erase(nums[i - k + 1]);
                sum -= nums[i - k + 1];
            }
            else {
                freq[nums[i]]++;
                sum += nums[i];
            }
        }

        return ans == INT_MIN ? 0 : ans;
    }
};