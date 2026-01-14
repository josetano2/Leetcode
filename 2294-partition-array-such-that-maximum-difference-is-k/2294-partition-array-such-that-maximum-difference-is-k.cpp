class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            int j = i;
            while(j < nums.size() && nums[j] - nums[i] <= k) j++;
            i = j - 1;
            count++;
        }
        
        return count;
    }
};