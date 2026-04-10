class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int len = 1, ans = 0, n = colors.size();
        for(int i = 1; i < n + k - 1; i++) {
            int prev = colors[(i - 1) % n], curr = colors[i % n];
            if(curr != prev) len++;
            else len = 1;

            if(len >= k) ans++;
        }

        return ans;
    }
};