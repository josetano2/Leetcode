class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        
        int ns = s.size();

        int pivot = -1;
        for(int i = ns - 1; i > 0; i--) {
            if(s[i - 1] < s[i]) {
                 pivot = i - 1; break;
            }
        }

        if(pivot == -1) return -1;

        int swapI = 0;
        for(int i = ns - 1; i >= pivot; i--) {
            if(s[i] > s[pivot]) {
                swapI = i; break;
            }
        }

        swap(s[pivot], s[swapI]);

        reverse(s.begin() + pivot + 1, s.end());
        long long ans = stoll(s);
        return ans > INT_MAX ? -1 : ans;
    }
};