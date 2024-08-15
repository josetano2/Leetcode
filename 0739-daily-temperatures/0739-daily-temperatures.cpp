#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int len = temperatures.size();
        vector<int> ans(len, 0);
        stack<pair<int, int>> stk;

        for(int i = 0; i < len; i++){
            if(stk.empty()){
                stk.push(make_pair(temperatures[i], i));
            }
            else{
                while(!stk.empty() && stk.top().first < temperatures[i]){
                    // cout << stk.top().first << " " << temperatures[i] << "\n";
                    ans[stk.top().second] = i - stk.top().second;
                    stk.pop();
                }
                stk.push(make_pair(temperatures[i], i));

            }
            

            }
    
        return ans;
    }
};

