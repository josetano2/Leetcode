class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> freq;
        int n = nums.size();
        for(int i = 0; i < n; i++) freq[nums[i]].push_back(i);
    
        vector<int> ans;
        for(auto& q : queries) {
            if(freq[nums[q]].size() == 1) {
                ans.push_back(-1); continue;
            }
            vector<int>& curr = freq[nums[q]];
            auto it = lower_bound(curr.begin(), curr.end(), q);
            int pos = it - curr.begin(), minDist = INT_MAX;

            if(pos - 1 >= 0) minDist = calculateMinDist(minDist, q, curr[pos - 1], n);
            
            if(pos < curr.size() && curr[pos] == q) {
                if(pos + 1 < curr.size()) minDist = calculateMinDist(minDist, q, curr[pos + 1], n);
            } 
            else if(pos < curr.size()) {
                minDist = calculateMinDist(minDist, q, curr[pos], n);
            }

            if(curr[0] != q) minDist = calculateMinDist(minDist, q, curr[0], n);
            if(curr[curr.size() - 1] != q) minDist = calculateMinDist(minDist, q, curr[curr.size() - 1], n);

            ans.push_back(minDist);
        }
        return ans;
    }

    int calculateMinDist(int minDist, int q, int num, int n) {
        return min({
            minDist,
            abs(q - num),
            abs(q - num + n),
            abs(q - num - n)
        });
    }
};