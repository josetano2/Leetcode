class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {

        unordered_map<int, int> mapIdx;
        int l = 0, r = 0, len = cards.size(), ans = INT_MAX;

        if(len == 1) return -1;

        while(r < len) {
            if(mapIdx[cards[r]]) ans = min(ans, r - mapIdx[cards[r]] + 1);
            mapIdx[cards[r]] = r;
            r++;
        }

        return ans == INT_MAX ? cards[0] == cards[r - 1] ? len : -1 : ans;

    }
};