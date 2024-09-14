class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int highest = -1, steps = 1, currHighestSteps = 1;

        for(auto x : nums) {
            if(x > highest){
                highest = x;
                currHighestSteps = 1; 
                steps = 1;
            }
            else if(x < highest){
                cout << currHighestSteps << " " << steps << endl;
                currHighestSteps = max(steps, currHighestSteps);
                steps = 0;
            }
            else {
                steps++;
            }
        }

        return max(currHighestSteps, steps);
        
    }
};