class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {

        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                freq[nums[i] * nums[j]]++;
            }
        }
        

        int ans = 0;
        for(auto& [a, b] : freq) {
            if(b >= 2) {
                ans += 8 * (b * (b - 1) / 2);
            }
        }

        return ans;
    }
};