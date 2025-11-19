class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> uSet;

        for(auto x : nums) uSet.insert(x);

        while(uSet.count(original)) {
            original *= 2;
        }

        return original;
    }
};