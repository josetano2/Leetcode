class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> diff(200001, 0);
        for(auto &x : nums) {
            int start = x - k, end = x + k;
            if(start < 0) start = 0;
            diff[start]++; diff[end + 1]--;
        }

        int ans = 1, curr = 0;
        for(auto& x : diff) {
            curr += x;
            ans = max(ans, curr);
        }

        return ans;
    }
};