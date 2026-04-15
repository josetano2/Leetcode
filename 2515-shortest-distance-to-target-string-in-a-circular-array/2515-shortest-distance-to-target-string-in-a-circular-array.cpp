class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size(), ans = INT_MAX;
        for(int i = 0; i < words.size(); i++) {
            if(words[i] == target) {
                ans = min({ans, abs(startIndex - i), abs(n - startIndex + i), abs(startIndex + n - i)});
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};