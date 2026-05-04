class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        sort(heaters.begin(), heaters.end());

        int ans = INT_MIN;
        for(auto& h : houses) {
            auto it = lower_bound(heaters.begin(), heaters.end(), h);
            int idx = it - heaters.begin();

            int c1 = INT_MAX, c2 = INT_MAX, closest = INT_MAX;
            if(idx != heaters.size()) c2 = heaters[idx];
            if(idx != 0) c1 = heaters[idx - 1];

            closest = min(abs(c1 - h), abs(c2 - h));
            ans = max(closest, ans);
        }
        return ans;
    }
};
