class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int highest = INT_MIN, consecutively = 1, ans = 1;

        for (auto x : nums) {
            if (x > highest) {
                highest = x;
                ans = 1;
                consecutively = 1;
            }

            else if (x == highest) {
                consecutively++;
            }

            else {
                ans = max(ans, consecutively);
                consecutively = 0;
            }
        }

        cout << ans << " " << consecutively << endl;
        return max(ans, consecutively);
    }
};