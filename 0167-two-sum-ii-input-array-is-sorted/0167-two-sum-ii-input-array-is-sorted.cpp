class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();

        int left = 0, right = len - 1;

        int flag = false;
        while(!flag){
            int res = target - numbers[left];
            if(res == numbers[right]){
                return {left + 1, right + 1};
            }
            else if(res < numbers[right]){
                right--;
            }
            else if(res > numbers[left]){
                left++;
            }
            else{
                flag = true;
            }  
        }
        return {0, 0};
    }
};