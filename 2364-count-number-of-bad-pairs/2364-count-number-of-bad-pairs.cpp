class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        long long n = (nums.size() * (nums.size() - 1)) / 2;
        unordered_map<int, long long> freq;

        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i] - i]++;
        }

        for(auto [x, y] : freq) {
            if(y > 1) {
                n -= (y * (y - 1)) / 2;
            }
        }
        return n;
    }
};