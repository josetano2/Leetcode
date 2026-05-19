class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int tot = -1, mp = 0, curr = 0, q = 0, count = 0;

        int i = 0;
        while(i < customers.size() || q > 0) {
            if(i < customers.size()) q += customers[i++];
            
            int cc = min(q, 4);
            q -= cc;
            curr += cc * boardingCost - runningCost;
            count++;

            if(curr > mp) {
                mp = curr;
                tot = count;
            }
        }

        return tot;
    }
};