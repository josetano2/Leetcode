class Solution {
public:
    int minRemoval(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> v(n, -1);

        for(int i = 0; i < nums.size(); i++) {
            long long toFind = nums[i] * k;
            auto it = upper_bound(nums.begin(), nums.end(), toFind);

            if(it != nums.begin()) {
                --it;
                v[i] = it - nums.begin();
            }
        }

        int ans = INT_MAX;
        for(int i = 0; i < n; i++) ans = min(ans, n - (v[i] - i) - 1);
        return ans == n ? 0 : ans;
    }
};