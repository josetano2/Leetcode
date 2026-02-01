class Solution {
public:
    int minimumCost(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++) pq.push(nums[i]);
        for(int i = 0; i < 2; i++) {
            ans += pq.top(); pq.pop();
        }
        return ans;
    }
};