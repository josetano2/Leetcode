class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, -1);
        stack<int> stk;

        for(int i = 0; i < nums.size(); i++) {
            while(!stk.empty()) {
                if(nums[stk.top()] < nums[i]) {
                    ans[stk.top()] = nums[i]; 
                    stk.pop();
                }
                else break;
            }

            stk.push(i);
        }

        for(int i = 0; i < nums.size(); i++) {
            while(!stk.empty()) {
                if(nums[stk.top()] < nums[i]) {
                    ans[stk.top()] = nums[i]; 
                    stk.pop();
                }
                else break;
            }
        }

        return ans;
    }
};