class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        int biggest = INT_MIN;
        for(auto& x : milestones) biggest = max(x, biggest);
        
        long long total = 0, flag = false;
        for(int i = 0; i < milestones.size(); i++) {
            if(milestones[i] == biggest && !flag) {
                flag = true; continue;
            }
            total += milestones[i];
        }
    
        if(total < biggest) total = total * 2 + 1;
        else total += biggest;

        return total;
    }
};