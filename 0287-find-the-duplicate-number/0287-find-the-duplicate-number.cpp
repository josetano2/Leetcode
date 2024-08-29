class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        unordered_map<int, int> uMap;

        for(auto x : nums){
            uMap[x]++;
            if(uMap[x] > 1){
                return x;
            }
        }

        return -1;
    }
};