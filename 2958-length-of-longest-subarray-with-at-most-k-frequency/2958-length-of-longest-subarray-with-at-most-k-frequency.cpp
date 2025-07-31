class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        unordered_map<int, int> uMap;

        int l = 0, r = 0, ans = INT_MIN;

        while(r < nums.size()) {
            if(uMap[nums[r]] < k) {
                uMap[nums[r]]++;
                r++;
            }
            else {
                ans = max(ans, r - l);
                while(uMap[nums[r]] >= k) {
                    uMap[nums[l]]--;
                    l++;
                }
            }
        }

        return max(ans, r - l);
    }
};