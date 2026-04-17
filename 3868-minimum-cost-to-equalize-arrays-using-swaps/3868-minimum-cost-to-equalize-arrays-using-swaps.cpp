class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um;

        for(int i = 0; i < nums1.size(); i++) {
            um[nums1[i]]++; um[nums2[i]]++;
        }
        for(auto& [x, y] : um) {
            if(y % 2 != 0) return -1;
            um[x] = y / 2;
        }
        for(int i = 0; i < nums1.size(); i++) um[nums1[i]]--;

        int tot = 0;
        for(auto& [x, y] : um) tot += abs(y);
        
        return tot / 2;
    }
};