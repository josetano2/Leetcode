class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        // true = p1, false = p2
        bool flag = true;
        int curr = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2 != 0) flag = !flag;
            if(i % 6 == 5) flag = !flag;

            curr = flag ? curr + nums[i] : curr - nums[i];
        }
        return curr;
    }
};