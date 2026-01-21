class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        unordered_map<char, int> freq;
        vector<string> ans;

        for(int i = 0; i < words2.size(); i++) {
            unordered_map<char, int> temp;
            for(auto& c : words2[i]) temp[c]++;

            for(auto& [f, s] : temp) {
                freq[f] = max(freq[f], s);
            }
        }

        for(int i = 0; i < words1.size(); i++) {
            
            unordered_map<char, int> temp;
            for(auto& c : words1[i]) temp[c]++;

            bool flag = false;

            for(auto& [x, y] : freq) {
                if(temp[x] == 0 || temp[x] < y) {
                    flag = true;
                    break;
                }
            }
            if(!flag) ans.push_back(words1[i]);
        }

        return ans;
    }
};