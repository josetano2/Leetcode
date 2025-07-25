class Solution {
public:
    int tot = 0;
    vector<bool> cache;

    bool canPartition(vector<int>& nums) {
        for (auto x : nums)
            tot += x;

        if (tot % 2 != 0)
            return false;
        cache = vector<bool>(tot / 2 + 1, false);
        cache[0] = true;

        // 0 1 2 3 4 5 6
        // T F T F F F F
        for (auto x : nums) {
            for (int i = tot / 2; i >= x; i--) {
                if (cache[i]) {
                    continue;
                }
                if (cache[i - x]) {
                    cache[i] = true;
                }
            }
        }
        return cache[tot / 2];
    }
};
