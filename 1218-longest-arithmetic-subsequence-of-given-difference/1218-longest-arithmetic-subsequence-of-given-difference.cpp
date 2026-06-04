class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> um;

        um[arr[0]] = 1;
        for(int i = 1; i < arr.size(); i++) {
            if(um.count(arr[i] - difference)) um[arr[i]] = um[arr[i] - difference] + 1;
            else um[arr[i]] = 1;
        }

        return max_element(
            um.begin(), 
            um.end(),
            [](const auto& p1, const auto& p2) {
                return p1.second < p2.second; 
            }
        )->second;
    }
};