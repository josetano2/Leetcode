class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // chance buat 0 itu ada
        // -1 0 1 2 -1 -4

        sort(nums.begin(), nums.end());
        // -4 -1 -1 0 1 2
        vector<vector<int>> ans;

        unordered_map<int, vector<int>> uMap;

        int len = nums.size();

        for(int i = 0; i < len - 1; i++){
            int x = nums[i];

            int left = i + 1, right = len - 1;
            bool flag = false;

            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            while(left < right){
                if(left >= len || right <= 0 || left == right){
                    break;
                }

                int res = x + nums[left] + nums[right];
                if(res == 0){
                    ans.push_back({x, nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left + 1]){
                        left++;
                    }
                    while(left < right && nums[right] == nums[right - 1]){
                        right--;
                    }
                    // left++;
                    right--;
                    continue;   
                }
                else if(res > 0){
                    right--;
                }
                else if(res < 0){
                    left++;
                }
            }
        }

        return ans;
    }
};