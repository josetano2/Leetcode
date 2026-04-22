class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        vector<int> ans;
        long long currPos = (long long) n * (n + 1) / 2, currNeg = 0;

        unordered_set<int> us;
        long long r = n * -1;
        if(currPos < target) return vector<int>(0);

        while(currPos > currNeg && abs(r) > 0) {
            long long diff = currPos + currNeg, goal = diff - target;
            if(goal == 0) break;
            if(goal / 2 <= abs(r)) {
                // found ans
                long long res = goal / 2 * -1;
                currNeg += res;
                currPos += res;

                ans.push_back(res);
                us.insert(res);
                break;
            }
            else {
                currNeg += r;
                currPos += r;
                ans.push_back(r);
                us.insert(r);

                r++;
            } 
        }

        cout << currNeg << " " << currPos << " " << endl;
        
        if(currPos + currNeg != target) return vector<int>(0);
         
        for(int i = 1; i <= n; i++) {
            if(us.find(i * -1) == us.end()) ans.push_back(i);
        }
        
        return ans;
    }
};