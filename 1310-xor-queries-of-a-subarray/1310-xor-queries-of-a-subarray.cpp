class Solution {
public:

    // brute force approach
    // vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    //     vector<int> ans;
    //     for(auto query : queries){

    //         int left = query[0], right = query[1], total = 0;
    //         while(left <= right){
    //             total = total ^ arr[left];
    //             left++;
    //         }

    //         ans.push_back(total);
    //     }
    //     return ans;
    // }

    // optimized
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
       
        int len = arr.size();
        int xors[len];
        xors[0] = arr[0];

        vector<int> ans;

        for(int i = 1; i < len; i++){
            xors[i] = xors[i - 1] ^ arr[i];     
        }
        
        for(auto q : queries){
            if(q[1] - q[0] == 0) ans.push_back(arr[q[1]]);
            else if(q[0] == 0) ans.push_back(xors[q[1]]);
            else ans.push_back(xors[q[1]] ^ xors[q[0] - 1]);
        }
        return ans;
    }
};