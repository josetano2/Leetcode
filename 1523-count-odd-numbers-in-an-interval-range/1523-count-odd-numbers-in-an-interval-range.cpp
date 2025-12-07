class Solution {
public:
    int countOdds(int low, int high) {
        int diff = (high - low) / 2;
        return low % 2 != 0 || high % 2 != 0 ? diff + 1 : diff;
    }
};