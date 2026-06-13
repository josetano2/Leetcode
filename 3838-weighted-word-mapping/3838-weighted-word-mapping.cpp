class Solution {
public:
    int totalStr(string s, vector<int>& weights) {
        int x = 0;
        for(auto& c : s) x += weights[c - 'a'];
        return x % 26;
    }
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(auto& w : words) ans += (25 - totalStr(w, weights)) + 'a';
        return ans;
    }
};