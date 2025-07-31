class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> uMap;
        uMap[0] = 1;
        int prefixSum = 0, ans = 0;
        for(auto x : nums) {
            prefixSum += x;
            int temp = prefixSum - k;
            if(uMap.count(temp)) {
                ans += uMap[temp];
            }
            uMap[prefixSum]++;
        }

        return ans;
    }
};