class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<long long>> pMap;
        for(int i = 0; i < nums.size(); i++) {
            if(pMap.find(nums[i]) == pMap.end()) {
                pMap[nums[i]].push_back(i);
            }
            else {
                pMap[nums[i]].push_back(pMap[nums[i]][pMap[nums[i]].size() - 1] + i);
            }
        }

        vector<long long> ans;
        unordered_map<int, int> track;
        for(int i = 0; i < nums.size(); i++) {
            if(pMap[nums[i]].size() == 1) ans.push_back(0);

            else {
                long long curr = track[nums[i]];
                track[nums[i]]++;
                vector<long long>& arr = pMap[nums[i]];
                long long totL = curr == 0 ? 0 : arr[curr - 1], totR = arr[arr.size() - 1] - arr[curr];
                long long freqL = curr + 1, freqR = arr.size() - curr;
                long long l = i * freqL - totL, r = totR - i * freqR;
                ans.push_back(r + l);
            }
        }

        return ans;
    }
};