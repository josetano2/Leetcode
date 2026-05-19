class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);

        int l = 0, r = 0;
        for(int i = 0; i < n; i++) {
            if(boxes[i] == '1') {
                if(i == 0) l++;
                else r++;
                ans[0] += i;
            }
        }
        
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + l - r;
            if(boxes[i] == '1') {
                l++; r--;
            }
        }

        return ans;
    }
};