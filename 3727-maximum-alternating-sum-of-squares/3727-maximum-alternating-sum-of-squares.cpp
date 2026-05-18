class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        multiset<int> ms;
        for(auto& x : nums) ms.insert(abs(x));

        long long ans = 0;
        while(!ms.empty()) {
            if(!ms.empty()) {
                ans += pow(*ms.rbegin(), 2);
                ms.erase(prev(ms.end()));
            }

            if(!ms.empty()) {
                ans -= pow(*ms.begin(), 2);
                ms.erase(ms.begin());
            }
        }

        return ans;
    }
};