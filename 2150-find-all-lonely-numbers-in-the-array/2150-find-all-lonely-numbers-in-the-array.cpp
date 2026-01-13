class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {

        unordered_map<int, int> freq;
        for(auto& x : nums) freq[x]++;

        vector<int> ans;
        for(auto& x : nums) {
            if(freq[x] == 1 && freq.count(x - 1) == 0 && freq.count(x + 1) == 0) ans.push_back(x);
        }

        return ans;
    }
};