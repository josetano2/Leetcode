class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        int allowedMap[26] = {0};
        int ans = words.size();

        for(auto x : allowed){
            allowedMap[x - 'a'] = 1;
        }

        for(auto x : words){
            for(auto y : x){
                if(allowedMap[y - 'a'] == 0){
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};