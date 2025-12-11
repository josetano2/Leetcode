class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int MOD = 3;

        unordered_map<int, multiset<int>> track;

        long long int tot = 0;
        for (int i = 0; i < nums.size(); i++) {
            tot += nums[i];
            int modVal = nums[i] % MOD;
            if (modVal != 0) track[modVal].insert(nums[i]);
        }
        int rem = tot % MOD;
        if (rem == 0)return tot;

        int toRemove = INT_MAX;
        if(rem == 1) {
            if(!track[1].empty()) toRemove = min(toRemove, *track[1].begin());
            if(track[2].size() >= 2) toRemove = min(toRemove, *track[2].begin() + *next(track[2].begin()));
        }
        else if(rem == 2) {
            if(!track[2].empty()) toRemove = min(toRemove, *track[2].begin());
            if(track[1].size() >= 2) toRemove = min(toRemove, *track[1].begin() + *next(track[1].begin()));
        }

        return toRemove == INT_MAX ? 0 : tot - toRemove;    
    }
};