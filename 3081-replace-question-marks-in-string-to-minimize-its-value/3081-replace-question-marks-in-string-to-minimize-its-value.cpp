class Solution {
public:
    struct comp {
        bool operator()(pair<char, int> a, pair<char, int> b) {
            if (a.second == b.second) return a.first > b.first;
            return a.second > b.second;
        }
    };

    string minimizeStringValue(string s) {
        unordered_map<char, int> freq;
        for(int i = 'a'; i <= 'z'; i++) freq[i] = 0;
        for(auto& x : s) freq[x]++;

        priority_queue<pair<char, int>, vector<pair<char, int>>, comp> pq;

        for(auto& [x, y] : freq) {
            if(x == '?') continue;
            pq.push({x, y});
        }

        int totalQuestion = freq['?'];

        string filled = "";
        while(totalQuestion > 0) {
            pair<char, int> top = pq.top();
            pq.pop();
            filled += top.first;
            pq.push({top.first, top.second + 1});
            totalQuestion--;
        }

        sort(filled.begin(), filled.end());
        int curr = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '?') {
                s[i] = filled[curr++];
            }
        }
        return s;
    }
};