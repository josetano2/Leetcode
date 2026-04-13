class Solution {
public:

    int findNextOne(string& s, int curr) {
        while(curr < s.size()) {
            if(s[curr] == '1') return curr;
            curr++;
        }
        return -1;
    }

    int findTotalBundledOne(string& s, int curr) {
        int total = 0;
        while(curr < s.size()) {
            if(s[curr] != '1') break;
            curr++; total++;
        }
        return total;
    }

    int totalOne(string& s) {
        int curr = 0, total = 0;
        while(curr < s.size()) {
            if(s[curr] == '1') total++;
            curr++;
        }
        return total;
    }

    int totalOneFromRight(string& s) {
        int curr = s.size() - 1, total = 0;
        while(curr >= 0) {
            if(s[curr] != '1') break;
            total++; curr--;
        }
        return total;
    }

    int maxOperations(string s) {
        int curr = 0, ans = 0, bundle = 0, total = totalOne(s), totalFromRight = totalOneFromRight(s);
        curr = findNextOne(s, curr);
        total -= totalFromRight;

        while(bundle != total && curr != -1) {
            int  currBundle = findTotalBundledOne(s, curr), next = findNextOne(s, curr + currBundle);
            bundle += currBundle;
            ans += bundle;
            curr = next;
        }

        return ans;
    }
};