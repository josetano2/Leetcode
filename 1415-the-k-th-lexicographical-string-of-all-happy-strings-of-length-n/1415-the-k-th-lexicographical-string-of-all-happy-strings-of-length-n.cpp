class Solution {
public:

    void backtrack(string curr, int idx, vector<char>& abc, vector<string>& happy, int n) {
        if(curr.size() == n) {
            happy.push_back(curr);
            return;
        }
        
        for(int i = 0; i < abc.size(); i++) {
            if(idx > 0 && curr[idx - 1] == abc[i]) continue;
            curr += abc[i];
            backtrack(curr, idx + 1, abc, happy, n);
            curr.pop_back(); 
        }
        return;
    }

    string getHappyString(int n, int k) {
        vector<char> abc = {'a', 'b', 'c'};
        
        vector<string> happy;
        backtrack("", 0, abc, happy, n);

        if(k > happy.size()) return "";
        return happy[k - 1];
    }
};