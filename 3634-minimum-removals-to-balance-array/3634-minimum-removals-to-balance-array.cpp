class Solution {
public:
    int minRemoval(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int j = 0;
        int longest = 0;

        for(int i = 0; i < n; i++) {
            while(j < n && (long long) nums[i] * k >= nums[j]) {
                j++;
            }

            longest = max(longest, j - i);
        }

        return n - longest;
    }
};