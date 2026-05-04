class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long n = nums.size(), tot = 0, totalPairs = n * (n - 1) / 2;

        vector<unordered_map<char, long long>> vc(to_string(nums[0]).size(), unordered_map<char, long long>());
        for(int i = 0; i < n; i++) {
            string curr = to_string(nums[i]);
            for(int j = 0; j < curr.size(); j++) vc[j][curr[j]]++;
        }

        for(int i = 0; i < vc.size(); i++) {
            long long temp = 0;
            for(auto& [k, v] : vc[i]) temp += (v * (v - 1)) / 2;
            tot += (totalPairs - temp);
        }

        return tot;
    }
};