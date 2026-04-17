class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = INT_MIN, mid = 0;
        for(int i = 0; i < nums.size(); i++) r = max(r, nums[i]);

        while(l <= r) {
            int curr = 0;
            mid = l + (r - l) / 2;

            bool flag = true;
            for(auto& x : nums) {
                curr += ((x + mid - 1) / mid) - 1;
                if(curr > maxOperations) {
                    flag = false; break;
                }
            }

            if(flag) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};