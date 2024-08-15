class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int, int> numMap;

        int len = nums.size(), count = 1;
        if(len == 0){
            return 0;
        }

        for(int i = 0; i < len; i++){
            numMap[nums[i]] = 1;
        }

        for(int i = 0; i < len; i++){
            if(numMap.count(nums[i] - 1) != 0){
                numMap[nums[i]] = 0;
            }
        }

        for(int i = 0; i < len; i++){
            if(numMap[nums[i]] == 1){
                int temp = 1, res = 1;
                while(numMap.count(nums[i] + res) == 1){
                    temp++, res++;
                }

                if(temp > count){
                    count = temp;
                }
            }
        }

        return count;
    }
};