class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        unordered_map<char, int> pFreq;
        vector<int> ans;

        for(auto x : p) pFreq[x]++;

        int len = s.length();
        unordered_map<char, int> sFreq;

        int l = 0, r = 0;

        while(r < len) {
            if(pFreq.find(s[r]) != pFreq.end()) {
                sFreq[s[r]]++;
                r++;
            }
            else {
                l++;
                r = l;
                sFreq.clear();
            }

            if(pFreq == sFreq) {
                ans.push_back(l);
            }

            if(r - l >= p.length()) {
                sFreq[s[l]]--;
                if(sFreq[s[l]] == 0) sFreq.erase(s[l]);
                l++;
            }
        }
        
        return ans;
    }
};