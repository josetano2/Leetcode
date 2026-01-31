class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(target == 'z') return letters[0];
        char ans = 'z' + 1; for(auto l : letters) if(l > target && l < ans) ans = l;
        return ans == 'z' + 1 ? letters[0] : ans;
    }
};