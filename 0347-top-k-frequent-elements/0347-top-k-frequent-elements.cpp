class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> numFreq;

        int len = nums.size();

        int max = -1;
        for(int i = 0; i < len; i++){
            numFreq[nums[i]]++;
            if(numFreq[nums[i]] > max){
                max = numFreq[nums[i]];
            }
        }

        cout << max << endl;

        while(ans.size() != k){
            for (auto x : numFreq){
                if(x.second == max){
                    ans.push_back(x.first);
                }
            }
            max--;
        }
        return ans;
    }
};