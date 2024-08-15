class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        unordered_map<string, vector<string>> uMap;
        for(string x : strs){
            string temp = x;
            sort(temp.begin(), temp.end());

            uMap[temp].push_back(x);
        }

        for(auto x : uMap){
            ans.push_back(x.second);
        }

        return ans;
    }

};