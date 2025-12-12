class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            if(stoi(a[1]) == stoi(b[1])) return a[0] > b[0];
            return stoi(a[1]) < stoi(b[1]);
        });

        vector<vector<int>> mentions(numberOfUsers, {0, -1});
        for(auto& event : events) {
            string msgEvent = event[0];
            int timestamp = stoi(event[1]);

            if(msgEvent == "MESSAGE") {
                string scope = event[2];

                if(scope == "HERE") {
                    for(auto& x : mentions) {
                        if(x[1] <= timestamp || x[1] == -1) x[0]++;
                    }
                }
                else if(scope == "ALL") {
                    for(auto& x : mentions) x[0]++;
                    
                }
                else {
                    vector<int> tags;
                    stringstream ss(scope);
                    string word;

                    while (ss >> word) mentions[stoi(word.substr(2))][0]++;
                }
            }
            else {
                int id = stoi(event[2]);
                mentions[id][1] = timestamp + 60;
            }
        }

        vector<int> ans;
        for(auto& x : mentions) ans.push_back(x[0]);
        return ans;
        
    }
};