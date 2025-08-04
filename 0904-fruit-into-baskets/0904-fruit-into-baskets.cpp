class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int, int> uMap;
        int l = 0, ans = 0;

        for(int r = 0; r < fruits.size(); r++) {
            uMap[fruits[r]]++;

            while(uMap.size() > 2) {
                uMap[fruits[l]]--;
                if(uMap[fruits[l]] == 0) {
                    uMap.erase(fruits[l]);
                }
                l++;
            }
            
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};