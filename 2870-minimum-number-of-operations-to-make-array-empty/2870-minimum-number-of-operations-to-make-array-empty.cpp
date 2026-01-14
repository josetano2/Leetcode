class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(auto& x : nums) freq[x]++;

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
            cout << x << " " << y << " : " << count << endl;
        }

        return count;
        
    }
};