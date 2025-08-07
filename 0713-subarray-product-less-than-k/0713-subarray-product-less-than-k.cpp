class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int count = 0, l = 0, r = 0;
        long long int curr = 1;

        while (r < nums.size() && l < nums.size()) {
            if(curr == 0) curr = 1;
            curr *= nums[r];

            if (curr < k) {
                count += (r - l + 1);
                r++;
            } else {
                curr /= nums[l];
                curr /= nums[r];
                l++;
                if(l > r) r = l;
            }
        }

        return count;
    }
};