class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> m;

        for(int i = 0; i < messages.size(); i++) {
            stringstream ss(messages[i]);
            string token;
            vector<string> parts;
            while (getline(ss, token, ' ')) parts.push_back(token);

            int ms = parts.size();
            m[senders[i]] += ms;
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