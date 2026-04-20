class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // if(k > nums.size()) return;

        k = k % nums.size();
        cout << k << endl;
        vector<int> temp;

        for(int i = nums.size() - k; i < nums.size(); i++) {
            temp.push_back(nums[i]);
        }

        for(int i = 0; i < nums.size() - k; i++) {
            temp.push_back(nums[i]);

        }

        nums = temp;
    }
};