class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        int ans = 0, len1 = arr1.size(), len2 = arr2.size();
        unordered_set<string> uSet;

        for (int i = 0; i < len1; i++) {
            string curr = to_string(arr1[i]), temp = "";

            for (auto x : curr) {
                temp += x;
                uSet.insert(temp);
            }
        }

        for (int i = 0; i < len2; i++) {
            string curr = to_string(arr2[i]), temp = "";
            int count = 0;

            for (auto x : curr) {
                temp += x;
                count++;

                if (uSet.find(temp) != uSet.end()) {
                    ans = max(count, ans);
                }
            }
        }

        return ans;
    }
};