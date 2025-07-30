class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> uSet;

        for(auto x : nums) {
            uSet.insert(x);
        }

        int counter = 1, ans = 0;
        for(auto x : uSet) {
            counter = 1;
            int curr = x + 1;
            while(uSet.find(curr) != uSet.end()) {
                uSet.erase(curr);
                counter++;
                curr++;
            }

            curr = x - 1;
            while(uSet.find(curr) != uSet.end()) {
                uSet.erase(curr);
                counter++;
                curr--;
            }
            ans = max(ans, counter);
        }

        return ans;
    }
};