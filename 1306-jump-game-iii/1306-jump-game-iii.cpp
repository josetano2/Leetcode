class Solution {
public:
    void dfs(int idx, bool& flag, vector<int>& arr, vector<bool>& isVisited) {
        if(idx < 0 || idx >= arr.size() || isVisited[idx]) return;

        if(arr[idx] == 0) {
            flag = true;
            return;
        }
        
        isVisited[idx] = true;
        dfs(idx + arr[idx], flag, arr, isVisited);
        dfs(idx - arr[idx], flag, arr, isVisited);
    }

    bool canReach(vector<int>& arr, int start) {
        bool flag = false;
        vector<bool> isVisited = vector<bool>(arr.size(), false);
        dfs(start, flag, arr, isVisited);
        return flag;
    }
};