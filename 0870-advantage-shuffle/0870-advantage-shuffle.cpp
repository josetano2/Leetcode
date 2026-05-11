class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        for(auto& x : nums1) m[x]++;

        vector<int> ans;
        for(auto& x : nums2) {
            auto it = m.upper_bound(x);
            int front = it != m.end() ? it->first : m.begin()->first;     
            ans.push_back(front);
            m[front]--;
            if(m[front] == 0) m.erase(front);
        }

        return ans;
    }
};