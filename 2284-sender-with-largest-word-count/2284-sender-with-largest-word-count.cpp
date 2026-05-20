class Solution {
public:

    int countWords(string s) {
        int count = 1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') count++;
        }
        return count;
    }

    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> m;

        for(int i = 0; i < messages.size(); i++) {
            m[senders[i]] += countWords(messages[i]);
        }
        
        string ans = "";
        int mc = INT_MIN;

        for (auto& [name, count] : m) {
            if (count > mc || (count == mc && name > ans)) {
                mc = count;
                ans = name;
            }
        }
        return ans;
    }
};