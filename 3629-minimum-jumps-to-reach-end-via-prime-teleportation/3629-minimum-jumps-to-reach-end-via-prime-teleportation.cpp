class Solution {
public:

    int minJumps(vector<int>& nums) {
        int n = nums.size(), maxVal = *max_element(nums.begin(), nums.end());    
        unordered_map<int, vector<int>> um;
        for(int i = 0; i < n; i++) um[nums[i]].push_back(i);

        vector<bool> isPrime(maxVal + 1, true);
        isPrime[0] = isPrime[1] = false;

        vector<vector<int>> bucket(maxVal + 1);
        vector<bool> visited(n, false);
        for(int i = 2; i <= maxVal; i++) {
            if(isPrime[i]) {
                for(int j = i; j <= maxVal; j += i) {
                    if(j != i) isPrime[j] = false;
                    if(um.count(j)) {
                        for(auto& idx : um[j]) {
                            bucket[i].push_back(idx);
                        }
                    }
                }
            }
        }

        queue<int> q;
        q.push(0);
        visited[0] = true;

        int ans = 0;
        while(!q.empty()) {
            int len = q.size();

            for(int i = 0; i < len; i++) {
                int top = q.front();
                if(top == n - 1) return ans;
                if(top + 1 < n && !visited[top + 1]) {
                    visited[top + 1] = true;
                    q.push(top + 1);
                }
                if(top - 1 >= 0 && !visited[top - 1]) {
                    visited[top - 1] = true;
                    q.push(top - 1);
                }

                if(isPrime[nums[top]]) {
                    for(auto& idx : bucket[nums[top]]) {
                        if(!visited[idx]) {
                            visited[idx] = true;
                            q.push(idx);
                        }
                    }
                    bucket[nums[top]].clear();
                }
                q.pop();
            }

            ans++;
        }

        return ans;
    }
};