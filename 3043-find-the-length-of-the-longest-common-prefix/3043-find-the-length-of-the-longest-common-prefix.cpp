class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        int ans = 0, len1 = arr1.size(), len2 = arr2.size();
        unordered_set<int> uSet;

        for (int i = 0; i < len1; i++) {
            int temp = arr1[i];

            while (temp > 0) {
                uSet.insert(temp);
                temp /= 10;
            }
        }

        for (int i = 0; i < len2; i++) {
            int count = 0, temp = arr2[i], len = to_string(arr2[i]).size();

            while (temp > 0) {
                len--;
                if (uSet.find(temp) == uSet.end()) {
                    ans = max(len, ans);
                }
                temp /= 10;
            }
        }

        return ans;
    }
};