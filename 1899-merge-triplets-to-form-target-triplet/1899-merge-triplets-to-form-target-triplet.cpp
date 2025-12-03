class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {

        int first = target[0], second = target[1], third = target[2];

        for (int i = 0; i < triplets.size(); i++) {
            vector<int> curr = triplets[i];
            
            if (curr[0] == first && curr[1] == second && curr[2] == third) return true;
            if (curr[0] > first || curr[1] > second || curr[2] > third) continue;

            if (curr[0] == first || curr[1] == second || curr[2] == third) {
                for (int j = 0; j < triplets.size(); j++) {
                    vector<int>& temp = triplets[j];
                    if(temp[0] > first || temp[1] > second || temp[2] > third || i == j) continue;

                    int maxFirst = max(curr[0], temp[0]);
                    int maxSecond = max(curr[1], temp[1]);
                    int maxThird = max(curr[2], temp[2]);

                    if(maxFirst == first && maxSecond == second && maxThird == third) return true;

                    temp[0] = maxFirst;
                    temp[1] = maxSecond;
                    temp[2] = maxThird;        
                }
            }
        }

        return false;
    }
};