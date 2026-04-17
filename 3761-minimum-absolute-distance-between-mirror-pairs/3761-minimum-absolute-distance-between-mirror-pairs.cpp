class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> um;
        unordered_set<int> us;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 10 == 0) um[nums[i] / pow(10, (int) log10(nums[i]))].push_back(i);
            um[nums[i]].push_back(i);
            us.insert(nums[i]);
        }

        int ans = INT_MAX;
        unordered_map<int, int> reversedLookup;
        for(int i = 0; i < nums.size(); i++) {
            int power = (nums[i] == 0) ? 0 : (int) log10(nums[i]), n = 0;

            if(reversedLookup.find(nums[i]) != reversedLookup.end()) {
                n = reversedLookup[nums[i]];
                reversedLookup[nums[i]] = n;
            }
            else n = reverseNum(nums[i], power);
            vector<int> u = um[nums[i]];

            for(int x = 0; x < u.size(); x++) {
                if(um.find(n) != um.end() && us.find(n) != us.end()) {
                    vector<int> v = um[n];
                    if(v.size() > 1) {
                        for(int j = 0; j < v.size(); j++) {
                            if(u[x] - v[j] == 0) continue;
                            if(v[j] > u[x]) {
                                if(nums[v[j]] % 10 == 0 && nums[u[x]] < nums[v[j]]) continue;
                                ans = min(ans, v[j] - u[x]);
                            }
                        }
                    }
                    else if(v.size() == 1 && abs(v[0] - u[x]) != 0) ans = min(ans, abs(v[0] - u[x]));
                    if(ans == 1) return 1;
                }
            }
            if(nums[i] % 10 != 0) um.erase(n);
            um.erase(nums[i]);
        }

        return ans == INT_MAX ? -1 : ans;
    }

    int reverseNum(int x, int power) {
        int pos = pow(10, power), n = 0;
        for(int i = 0; i <= power; i++) {
            int end = x % 10;
            n += end * pos;
            x /= 10;
            pos /= 10;
        }

        return n;
    }
};