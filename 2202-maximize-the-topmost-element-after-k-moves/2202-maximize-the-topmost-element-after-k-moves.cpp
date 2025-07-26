class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {

        if (k == 0)
            return nums[0];
        if (nums.size() == 1) {
            if(k % 2 != 0)return -1;
            else return nums[0];
        }
        

        stack<int> stk;

        for (int i = nums.size() - 1; i >= 0; i--)
            stk.push(nums[i]);

        int highest = INT_MIN;
        while (k > 1 && !stk.empty()) {
            highest = max(stk.top(), highest);
            stk.pop();
            k--;
        }

        if (!stk.empty()) {
            stk.pop();
            highest = !stk.empty() ? max(stk.top(), highest) : highest;
        }
        return highest;
    }
    // A more optimized solution ?

    // int maximumTop(vector<int>& nums, int k) {
    //     int n = nums.size();

    //     if (k == 0) return nums[0];
    //     if (n == 1) return (k % 2 == 0) ? nums[0] : -1;

    //     int maxVal = INT_MIN;

    //     for (int i = 0; i < min(k - 1, n); ++i)
    //         maxVal = max(maxVal, nums[i]);

    //     if (k < n)
    //         maxVal = max(maxVal, nums[k]);

    //     return maxVal;
    // }
};