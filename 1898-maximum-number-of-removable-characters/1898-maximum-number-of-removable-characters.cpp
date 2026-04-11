class Solution {
public:
    bool checkSubSeq(string s, string p, unordered_set<int>& skipped) {
        int i = 0, j = 0;
        while (i < s.size() && j < p.size()) {
            if(skipped.count(i)) {
                i++; continue;
            }
            if (s[i] == p[j]) j++;
            i++;
        }
        return j == p.size();
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = 0, r = removable.size() - 1, mid = 0;

        unordered_set<int> removed;
        while(l <= r) {
            mid = l + (r - l) / 2;

            unordered_set<int> removed(removable.begin(), removable.begin() + mid + 1);
            if(checkSubSeq(s, p, removed)) l = mid + 1;
            else r = mid - 1;
        }

        return l;
    }
};