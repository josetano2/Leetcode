class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int len = prices.size(), profit = 0, minPos = 0;

        for(int i = 0; i < len - 1; i++){
            if(prices[i] < prices[minPos]){
                minPos = i;
            }

            int diff = prices[i + 1] - prices[minPos];
            if(diff > profit){
                profit = diff;
            }
        }

        return profit;
       
    }
};