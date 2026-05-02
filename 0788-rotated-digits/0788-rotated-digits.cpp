class Solution {
public:
    unordered_set<char> invalid = {'3', '4', '7'};
    unordered_set<char> flip = {'2', '5', '6', '9'};

    int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            string s = to_string(i);

            bool isValid = true, hasFlip = false;
            for(auto& c : s) {
                if(invalid.contains(c)) {
                    isValid = false; break;
                }
                if(flip.contains(c)) {
                    hasFlip = true;
                }
            }

            if(isValid && hasFlip) ans++;
        }

        return ans;
    }
};