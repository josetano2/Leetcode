class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> uSet;

        for(auto x : nums) uSet.insert(x);

        while(uSet.find(original) != uSet.end()) {
            original *= 2;
        }

        return original;
    }
};