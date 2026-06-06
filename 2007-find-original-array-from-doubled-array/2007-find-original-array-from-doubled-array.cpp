class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        unordered_map<int, int> um;
        vector<int> ans;

        int n = changed.size(), count = n / 2;
        for(int i = 0; i < n; i++) um[changed[i]]++;

        for(int i = 0; i < n; i++) {
            if(um[changed[i]] == 0) continue;

            um[changed[i]]--;

            if(um[changed[i] * 2] == 0) return {};
            
            um[changed[i] * 2]--;
            ans.push_back(changed[i]);
        }

        return ans.size() == n / 2 ? ans : vector<int>();
    }
};