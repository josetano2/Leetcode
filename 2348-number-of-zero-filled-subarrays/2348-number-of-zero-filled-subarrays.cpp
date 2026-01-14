class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long z = 0;

        for(auto& x : nums) {
            if(x == 0) z++;
            else if(z > 0) {
                count += (z * (z + 1)) / 2;
                z = 0;
            }
        }
        
        return count += (z * (z + 1)) / 2;
    }
};