class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, bool> uMap;

        int smallest = INT_MAX, highest = INT_MIN;
        for (auto x : nums) {
            smallest = min(smallest, x);
            highest = max(highest, x);
            if (x < 0 && uMap.count(abs(x)))
                continue;
            if (x > 0 && uMap.count(x * -1)) {
                uMap.erase(x * -1);
            }
            uMap[x] = true;
        }

        int ans = smallest < 0 && highest < 0 ? INT_MIN : 0;
        cout << smallest << endl;
        for (auto x : uMap) {
            if (ans >= 0 && x.first > 0) {
                ans += x.first;
            }
            
            if(x.first < 0) {
                ans = max(ans, x.first);
            }

        }

        return ans;
    }
};
