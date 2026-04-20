class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        int l = -1, r = -1;
        if(!left.empty()) r = left[left.size() - 1];
        if(!right.empty()) l = n - right[0];

        return max(l, r);
    }
};