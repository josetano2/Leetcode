class Solution {
public:

    bool flag = false;
    vector<bool> isVisited;
    void dfs(int idx, vector<int>& arr) {
        if(idx < 0 || idx > arr.size() || isVisited[idx]) return;
        if(arr[idx] == 0) {
            flag = true;
            return;
        }
        
        isVisited[idx] = true;
        dfs(idx + arr[idx], arr);
        dfs(idx - arr[idx], arr);
    }

    bool canReach(vector<int>& arr, int start) {
        isVisited = vector<bool>(arr.size(), false);
        dfs(start, arr);
        return flag;
    }
};