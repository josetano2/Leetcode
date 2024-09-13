class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        vector<int> ans;

        for(auto query : queries){

            int left = query[0], right = query[1], total = 0;
            while(left <= right){
                total = total ^ arr[left];
                left++;
            }

            ans.push_back(total);
        }
        return ans;
    }
};