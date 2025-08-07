class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

        int minSkill = INT_MAX, maxSkill = INT_MIN;
        unordered_map<int, int> freq;

        for (auto x : skill) {
            freq[x]++;
            minSkill = min(minSkill, x);
            maxSkill = max(maxSkill, x);
        }

        // Every number must satisfy this
        long long int avgSkill = minSkill + maxSkill,
            mid = avgSkill % 2 == 0 ? avgSkill / 2 : avgSkill / 2 + 1;
        long long int ans = 0;

        while (mid >= minSkill) {
            cout << mid << " " << ans << endl;
            if (mid * 2 == avgSkill) {
                if(freq[mid] % 2 != 0) return -1;

                int possiblePair = freq[mid] / 2;
                ans += (mid * mid * possiblePair);
                freq[mid] = 0;
            } else {

                int rem = avgSkill - mid;
                if(freq[rem] == freq[mid]) {
                    ans += (rem * mid * freq[rem]);
                    freq[rem] = 0;
                    freq[mid] = 0;
                }
                else if(freq[mid] == 0 && freq[rem] == 0) {
                    mid--;
                    continue;
                }
                else {
                    return -1;
                }
            }
            mid--;
        }

        return ans;
    }
};