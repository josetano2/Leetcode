class Solution {
public:
    set<vector<int>> unique;
    vector<vector<int>> ans;

    void backtrack(int idx, vector<int>& curr, vector<int>& nums) {
        cout << "Index: " << idx << endl;
        for (auto x : curr) {
            cout << x << " ";
        }
        cout << endl;
        if (idx >= nums.size() && !unique.count(curr)) {
            cout << "MASUK" << endl;
            ans.push_back(vector<int>(curr));
            unique.insert(vector<int>(curr));
            return;
        }

        if (idx >= nums.size())
            return;

        cout << "Push" << endl << endl;
        
        curr.push_back(nums[idx]);
        backtrack(idx + 1, curr, nums);

        cout << "Pop" << endl << endl;
        curr.pop_back();
        backtrack(idx + 1, curr, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(0, curr, nums);
        return ans;
    }
};