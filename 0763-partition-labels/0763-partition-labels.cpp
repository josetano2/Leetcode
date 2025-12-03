class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        for(int i = 0; i < s.size(); i++) {
            int curr = s[i] - 'a';
            if(first[curr] == -1) {
                first[curr] = i;
                last[curr] = i;
                continue;
            }
            last[curr] = i;
        }

        vector<int> ans;
        int startIdx = first[s[0] - 'a'];
        int lastIdx = last[s[0] - 'a'];

        for(int i = 1; i < s.size(); i++) {
            int curr = s[i] - 'a';
            if(first[curr] > lastIdx) {
                ans.push_back(lastIdx - startIdx + 1);
                startIdx = first[curr];
            }
            lastIdx = max(last[curr], lastIdx);
        }

        ans.push_back(lastIdx - startIdx + 1);

        return ans;
    }
};