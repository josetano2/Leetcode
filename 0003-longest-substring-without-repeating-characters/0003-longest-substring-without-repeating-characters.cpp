class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();

        if(len <= 1){
            return len;
        }

        int left = 0, right = 0, ans = -1;
        unordered_set<char> charSet;

        while(right < len){
            if(charSet.find(s[right]) == charSet.end()){
                charSet.insert(s[right]);
                right++;
                ans = max(ans, right - left);
            }
            else{
                charSet.erase(s[left]);
                left++;
            }
        }

        return ans;
    }
};