class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        priority_queue<int> cap;
        int tot = 0;
        for(auto& x : capacity) cap.push(x);
        for(auto& x : apple) tot += x;
    
        int curr = 0, ans = 0;
        while(curr < tot) {
            curr += cap.top();
            cap.pop();
            ans++;
        }

        return ans;
    }
};