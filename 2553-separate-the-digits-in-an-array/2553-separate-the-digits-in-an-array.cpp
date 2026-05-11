class Solution {
public:

    vector<int> seperate(int n) {
        vector<int> temp;
        while(n > 0) {
            temp.push_back(n % 10);
            n /= 10;
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }

    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto& x : nums) {
            vector<int> curr = seperate(x);
            ans.insert(ans.end(), curr.begin(), curr.end()); 
        }
        return ans;
    }
};