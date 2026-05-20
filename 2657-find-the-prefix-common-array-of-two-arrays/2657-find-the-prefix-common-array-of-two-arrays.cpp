class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> p(n);

        for(int i = 0; i < n; i++) p[A[i] - 1] = i;

        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            int idx = p[B[i] - 1];

            if(idx > i) ans[idx]++;
            else ans[i]++;
        }

        for(int i = 1; i < n; i++) ans[i] = ans[i] + ans[i - 1];
        
        return ans;

    }
};