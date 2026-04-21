class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        sort(milestones.begin(), milestones.end());
        
        long long total = 0;
        for(int i = 0; i < milestones.size() - 1; i++) total += milestones[i];

        if(total < milestones[milestones.size() - 1]) total = total * 2 + 1;
        else total += milestones[milestones.size() - 1];

        return total;
    }
};