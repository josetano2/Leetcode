class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        ans.push_back(1);

        for(int i = 0; i < n - 1; i++){
            int temp = ans[i];
            
            if(ans[i] * 10 <= n){
                ans.push_back(ans[i] * 10);
            }
            else{
                while(temp >= n || temp % 10 == 9){
                    temp /= 10;
                }
                if(temp <= n){
                    ans.push_back(temp + 1);
                }
            }
        }

        return ans;
    }
};