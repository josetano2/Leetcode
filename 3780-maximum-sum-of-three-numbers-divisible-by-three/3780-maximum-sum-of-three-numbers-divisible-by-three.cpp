class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int>> um;

        for(int i = 0; i < nums.size(); i++) {
            um[nums[i] % 3].push(nums[i]);
        }

        int ans = INT_MIN;
        if(um.size() == 3) {
            ans = max(ans, (int) (um[0].top() + um[1].top() + um[2].top()));
        }
        
        for(int i = 0; i < 3; i++) {
            if(um[i].size() >= 3) {
                int curr = 0;
                for(int j = 0; j < 3 && !um[i].empty(); j++) {
                    curr += um[i].top();
                    um[i].pop();
                }
                ans = max(ans, curr);
            }
        }

        return ans == INT_MIN ? 0 : ans;
    }
};