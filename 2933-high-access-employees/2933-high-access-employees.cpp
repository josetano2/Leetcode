class Solution {
public:

    int timeConvert(char s1, char s2) {
        return (s1 - '0') * 10 + (s2 - '0');
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        
        unordered_map<string, vector<string>> um;
        for(auto& x : access_times) um[x[0]].push_back(x[1]);

        vector<string> ans;
        for(auto& [x, y] : um) {
            if(y.size() < 3) continue;
            sort(y.begin(), y.end());

            int l = 0, r = 1, mm = 0, ss = 0;
            while(r < y.size()) {
                int currM = timeConvert(y[r][0], y[r][1]), currS = timeConvert(y[r][2], y[r][3]);
                mm = timeConvert(y[l][0], y[l][1]), ss = timeConvert(y[l][2], y[l][3]);
                if(currM >= mm && currM <= mm + 1 && ((currM == mm && currS >= ss) || (currM == mm + 1 && currS <= ss - 1))) r++;
                else {
                    l++; r = l + 1;
                }
                if(r - l == 3) {
                    ans.push_back(x); 
                    break;
                }
            }
        }

        return ans;
    }
};