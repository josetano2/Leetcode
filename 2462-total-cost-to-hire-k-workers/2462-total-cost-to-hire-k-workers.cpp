class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pqL, pqR;
        int l = 0, r = costs.size();
        for(int i = 0; i < candidates; i++){
            pqL.push({costs[i], i});
            l++;
        }

        for(int i = costs.size() - 1; i >= costs.size() - candidates; i--) {
            if(l >= r) break;
            pqR.push({costs[i], i});
            r--;
        }
        l--;

        long long ans = 0;
        while(k > 0) {
            if(!pqL.empty() && !pqR.empty()) {
                auto topL = pqL.top(), topR = pqR.top();
                if(topL < topR) {
                    ans += topL.first;
                    pqL.pop();

                    l++;
                    if(l < r) pqL.push({costs[l], l});
                }
                else {
                    ans += topR.first;
                    pqR.pop();
                    
                    r--;
                    if(l < r) pqR.push({costs[r], r});
                }
            }
            else {
                auto topL = pqL.top();
                ans += topL.first;
                pqL.pop();
            }
            if(r - l <= 1) {
                while(!pqR.empty()) {
                    auto topR = pqR.top();
                    pqR.pop();
                    pqL.push(topR);
                }
            }
            k--;
        }

        return ans;
    }
};