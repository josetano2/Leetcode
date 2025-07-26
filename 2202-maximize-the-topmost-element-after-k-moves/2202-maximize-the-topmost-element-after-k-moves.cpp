class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {

        if (k == 0)
            return nums[0];
        if (nums.size() == 1 && k <= nums.size())
            return -1;
        

        stack<int> stk;

        for (int i = nums.size() - 1; i >= 0; i--)
            stk.push(nums[i]);

        int highest = INT_MIN;
        while (k > 1 && !stk.empty()) {
            cout << stk.top() << endl;
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
};