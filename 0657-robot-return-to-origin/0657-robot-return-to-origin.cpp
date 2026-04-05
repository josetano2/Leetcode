class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, int> freq;
        for(auto &x : moves) freq[x]++;
        return freq['U'] == freq['D'] && freq['L'] == freq['R'];
    }
};