class Solution {
public:
    bool checkSubSeq(string& s, string& p, vector<bool>& skipped) {
        int i = 0, j = 0;
        while (i < s.size() && j < p.size()) {
            if(skipped[i]) { i++; continue; }
            if (s[i] == p[j]) j++;
            i++;
        }
        return j == p.size();
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = 0, r = removable.size();

        while(l < r) {
            int mid = l + (r - l + 1) / 2;

            vector<bool> removed(s.size(), false);
            for(int i = 0; i < mid; i++) removed[removable[i]] = true;

            if(checkSubSeq(s, p, removed)) l = mid;
            else r = mid - 1;
        }

        return l;
    }
};