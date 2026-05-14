class Solution {
public:
    bool isGood(vector<int>& nums) {
        vector<int> freq(201, 0);
        int mv = *max_element(nums.begin(), nums.end());
        for(auto& n : nums) freq[n]++;

        for(int i = 1; i < mv; i++) {
            if(freq[i] != 1) return false;
        }
        return freq[mv] == 2 ? true : false;
    }
};