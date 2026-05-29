class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(auto& x : nums) {

            int diff = 10, curr = 0;
            while(x > 0) {
                curr += x % diff;
                x /= 10;
            }
            ans = min(ans, curr);
        }

        return ans;
    }
};