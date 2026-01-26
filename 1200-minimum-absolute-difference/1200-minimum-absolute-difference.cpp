class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        unordered_set<int> freq;
        vector<vector<int>> ans;
        for(int i = 0; i < arr.size() - 1; i++) {
            minDiff = min(minDiff, abs(arr[i + 1] - arr[i]));
            freq.insert(arr[i]);
        }
        freq.insert(arr[arr.size() - 1]);

        for(int i = 0; i < arr.size(); i++) {
            int toSearch = minDiff + arr[i];
            if(freq.find(toSearch) != freq.end()) {
                ans.push_back({arr[i], toSearch});
                freq.erase(toSearch); freq.erase(arr[i]);
            }
        }
    
        return ans;
    }
};