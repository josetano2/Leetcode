class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        int biggest = INT_MIN;
        for(auto& x : milestones) biggest = max(x, biggest);
        
        long long total = 0;
        for(int i = 0; i < milestones.size(); i++) if(milestones[i] != biggest) total += milestones[i];;
    
        if(total < biggest) total = total * 2 + 1;
        else total += biggest;

        return total;
    }
};