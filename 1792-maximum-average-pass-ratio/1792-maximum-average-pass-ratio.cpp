class Solution {
public:

    double calculateDiff(double pass, double student) {
        return ((pass + 1)/(student + 1)) - (pass/student);
    }
    
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;

        for(int i = 0; i < classes.size(); i++) {
            pq.push({calculateDiff(classes[i][0], classes[i][1]), i}); 
        }

        while(extraStudents > 0) {
            auto [topDiff, i] = pq.top();
            pq.pop();
            classes[i][0]++; classes[i][1]++;
            pq.push({calculateDiff(classes[i][0], classes[i][1]), i}); 
            extraStudents--;
        }

        double tot = 0;
        for(auto& x : classes) {
            tot += (double) x[0] / x[1];
        }

        return tot / classes.size();
        
        
    }
};