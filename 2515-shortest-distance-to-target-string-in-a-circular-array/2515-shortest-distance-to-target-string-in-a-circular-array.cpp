class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        unordered_map<string, vector<int>> freq;
        int n = words.size();
        for(int i = 0; i < words.size(); i++) {
            freq[words[i]].push_back(i);
        }

        int ans = INT_MAX;
        if(freq.find(target) == freq.end()) return -1;

        for(int i = 0; i < freq[target].size(); i++) {
            int x = freq[target][i];
            cout << startIndex << " " << freq[target][i] << " " << n << endl;
            ans = min({ans, abs(startIndex - x), abs(n - startIndex + x), abs(startIndex + n - x)});
        }
        return ans;
    }
};