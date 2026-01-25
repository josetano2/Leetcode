class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int l = 0, r = 1;
        freq[nums[l]]++;
        pair<int, int> p = {nums[l], freq[nums[l]]};

        while(r < nums.size()) {
            freq[nums[r]]++;
            if(freq[nums[r]] > p.second) {
                    p.first = nums[r]; p.second = freq[nums[r]];
                }
            if(r - l + 1 - p.second <= k) {
                r++;
            }
            else {
                freq[nums[l]]--;
                l++;
            }
        }

        for(auto& x : freq) cout << x.first << " " << x.second << endl << endl;
        cout << p.first << " " << p.second << endl;
        return p.second;
    }
};