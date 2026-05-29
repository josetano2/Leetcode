class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> s;

        int l = 0, r = 0, count = 0, ans = 0, n = nums.size();
        while(l < n) {
            if(r >= n) {
                l++;
                r = l;
                count = 0;
                continue;
            }

            if(nums[r] % p == 0) count++;
            
            if(count <= k) {
                vector<int> curr(nums.begin() + l, nums.begin() + r + 1);
                if(!s.count(curr)) {
                    ans++;
                    s.insert(curr);
                }
            }
            else {
                l++;
                r = l;
                count = 0;
                continue;
            }
            r++;
        }

        return ans;
    }
};