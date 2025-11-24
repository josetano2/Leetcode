class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        long long int curr = 0;
        bool flag = false;

        vector<bool> ans;
        int power = 0;
        for(auto x : nums) {
            curr = (curr * 2 + x) % 5;
            ans.push_back(curr % 5 == 0);
        }

        return ans;
    }
};