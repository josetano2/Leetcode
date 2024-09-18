class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end(), [](const int& a, const int& b){
            string x = to_string(a), y = to_string(b);
            return x + y > y + x;
        });

        int len = nums.size();
        string ans = "";

        for(auto x : nums) if(ans[0] != '0' || x != 0) ans.append(to_string(x));
        return ans;

    }
};