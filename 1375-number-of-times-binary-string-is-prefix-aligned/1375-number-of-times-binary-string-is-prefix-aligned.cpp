class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int ans = 1, biggest = INT_MIN, flag = false;
        for(int i = 0; i < flips.size() - 1; i++) {
            biggest = max(flips[i], biggest);

            if(flips[i] == 1) flag = true;
            if(flag && (flips[i] == i + 1 && biggest == flips[i]) || (biggest == i + 1)) {
                cout << flips[i] << " " << i + 1 << " " << biggest << endl;
                ans++;
            }
        }

        return ans;
    }
};