class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int totalWeights = 0, maxW = INT_MIN;
        for(auto x : weights) {
            maxW = max(x, maxW);
            totalWeights += x;
        }
    
        int left = maxW, right = totalWeights, mid = 0;

        while(left < right) {
            mid = left + (right - left) / 2;
            long long int tot = 0;
            int totalDays = 1;

            for(auto x : weights) {
                if(tot + x <= mid) {
                    tot += x;
                }
                else {
                    totalDays++;
                    tot = x;
                }
            }

            if(totalDays <= days) {
                right = mid;
            }
            else {
                left = mid + 1;
            } 
        }

        return left;
        
    }
};