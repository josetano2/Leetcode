class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {

        int ans = INT_MAX;
        map<int, int> s;
        for(int i = 0; i < nums.size() - x; i++) s[nums[i + x]]++;

        for(int i = 0; i < nums.size() - x; i++) {
            auto it = s.lower_bound(nums[i]);
            
            if(it != s.begin()) --it;

            ans = min(ans, min(abs(it->first - nums[i]), abs(s.lower_bound(nums[i])->first - nums[i])));
            s[nums[i + x]]--;
            if(s[nums[i + x]] == 0) s.erase(nums[i + x]);
        }

        return ans;
    }
};