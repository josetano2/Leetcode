class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = prices.size(), MOD = 1e09+7;

        for(int i = 0; i < prices.size() - 1; i++) {
            int curr = i;
            while(curr < prices.size() - 1 && prices[curr] - prices[curr + 1] == 1) curr++;
            long long int n = curr - i + 1;
            ans = ans + (long long) (n * (n - 1) / 2);
            i = curr;
        }

        return ans;  
    }
};