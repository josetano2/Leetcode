class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> idx;

        for(int i = 0; i < boxes.size(); i++) if(boxes[i] == '1') idx.push_back(i);

        vector<int> ans;
        for(int i = 0; i < boxes.size(); i++) {
            int tot = 0;
            for(auto& j : idx) tot += (abs(j - i));
            ans.push_back(tot);
        }        
        return ans;
    }
};