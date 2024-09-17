class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> map1, map2;
        int len1 = s1.size(), len2 = s2.size();

        string temp = "";
        for(int i = 0; i < len1; i++){
            if(s1[i] != ' ' && i != len1 - 1) temp.push_back(s1[i]);
            else{
                if(i == len1 - 1) temp.push_back(s1[i]);
                map1[temp]++;
                temp = "";
            };
        }
        for(int i = 0; i < len2; i++){
            if(s2[i] != ' ' && i != len2 - 1) temp.push_back(s2[i]);
            else{
                if(i == len2 - 1) temp.push_back(s2[i]);
                map2[temp]++;
                temp = "";
            };
        }

        vector<string> ans;
        for(auto x : map1) if(x.second == 1 && map2[x.first] == 0) ans.push_back(x.first);
        for(auto x : map2) if(x.second == 1 && map1[x.first] == 0) ans.push_back(x.first);
        
        return ans;
    }
};