class Solution {
public:

    // Without Division
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> ans(nums.size(), 1);

        int prefixSum = 1;
        for(int i = 1; i < nums.size(); i++) {
            prefixSum *= nums[i - 1];
            ans[i] = prefixSum;
        }

        prefixSum = 1;
        for(int i = nums.size() - 1; i > 0; i--) {
            prefixSum *= nums[i];
            ans[i - 1] *= prefixSum;
        }

        return ans;
    }

    // With Division
    // vector<int> productExceptSelf(vector<int>& nums) {

    //     int total = 1, zeroCounter = 0;

    //     for (auto x : nums) {
    //         if (x == 0) {
    //             zeroCounter++;
    //             continue;
    //         }
    //         total *= x;
    //     }

    //     vector<int> ans;
    //     for (auto x : nums) {
    //         if (x != 0) {
    //             if (zeroCounter > 0) {
    //                 ans.push_back(0);
    //             } else {
    //                 ans.push_back(total / x);
    //             }
    //         } else {
    //             if (zeroCounter == 1) {
    //                 ans.push_back(total);
    //             } else {
    //                 ans.push_back(0);
    //             }
    //         }
    //     }
    //     return ans;
    // }
};