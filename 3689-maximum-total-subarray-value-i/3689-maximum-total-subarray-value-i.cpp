class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans = (long long) (*max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end())) * k;
        return ans;
    }
};