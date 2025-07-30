class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxProfit = 0, len = prices.size(), currHold = -1;

        for(int i = 0; i < len - 1; i++){

            if(prices[i] < prices[i + 1] && currHold == -1) {
                currHold = prices[i];
            }

            if(prices[i] > prices[i + 1] && currHold != -1) {
                maxProfit += (prices[i] - currHold);
                currHold = -1;
            }

        }

        if(currHold != -1) {
            maxProfit += (prices[len - 1] - currHold);
        }
        
        return maxProfit;
    }
};