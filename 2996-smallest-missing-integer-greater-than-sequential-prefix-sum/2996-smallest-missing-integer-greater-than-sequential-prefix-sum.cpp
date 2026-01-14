class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefixSum = nums[0];
        unordered_set<int> occ;
        occ.insert(nums[0]);

        bool flag = true;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1] + 1 && flag) prefixSum += nums[i];
            else flag = false;
            occ.insert(nums[i]);
        }

        while(occ.find(prefixSum) != occ.end()) prefixSum++;

        return prefixSum;
        
    }
};