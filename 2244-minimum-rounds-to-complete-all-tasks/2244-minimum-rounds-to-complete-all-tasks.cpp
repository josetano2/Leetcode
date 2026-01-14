class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;

        for(auto& x : tasks) freq[x]++;

        int count = 0;
        for(auto& [x, y] : freq) {
            if(y == 1) return -1;

            if(y == 2 || y == 3) count++;
            else if(y >= 3) {
                count += y / 3;
                if(y % 3 != 0) {
                    count++;
                }
            }
        }

        return count;
    }
};