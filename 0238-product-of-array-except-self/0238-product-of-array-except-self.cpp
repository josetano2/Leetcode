class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int total = 1, zeroCounter = 0;

        for (auto x : nums) {
            if (x == 0) {
                zeroCounter++;
                continue;
            }
            total *= x;
        }

        vector<int> ans;
        for (auto x : nums) {
            if (x != 0) {
                cout << (total) << " " << x << endl;
                if (zeroCounter > 0) {
                    ans.push_back(0);
                } else {
                    ans.push_back(total / x);
                }
            } else {
                if (zeroCounter == 1) {
                    ans.push_back(total);
                } else {
                    ans.push_back(0);
                }
            }
        }
        return ans;
    }
};