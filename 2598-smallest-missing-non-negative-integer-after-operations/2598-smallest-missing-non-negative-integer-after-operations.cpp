class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {

        unordered_set<int> tracker;
        int maxNum = INT_MIN;

        vector<int> residue(1000000, 0);

        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i] % value;
            if (curr < 0)
                curr += value;
            
            int newVal = curr + (residue[curr] * value);
            residue[curr]++;
            tracker.insert(newVal);
            maxNum = max(maxNum, newVal);
        }

        for (int i = 0; i < maxNum; i++) {
            if (tracker.find(i) == tracker.end()) {
                return i;
            }
        }

        return maxNum + 1;
    }
};