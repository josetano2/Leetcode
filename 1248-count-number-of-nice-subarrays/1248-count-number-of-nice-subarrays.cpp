class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int prefix = 0, ans = 0;
        unordered_map<int, int> um;
        um[0] = 1;

        for(int i = 0; i < nums.size(); i++) {
            prefix += nums[i] % 2;
            ans += um[prefix - k];
            um[prefix]++;
        }
                
        return ans;
    }
};