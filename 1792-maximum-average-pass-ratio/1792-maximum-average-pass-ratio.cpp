class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;
        for(int i = 0; i < classes.size(); i++) {
            double totPass = (double) classes[i][0], totStudent = (double) classes[i][1];
            double diff = ((totPass + 1)/(totStudent + 1)) - (totPass/totStudent);
            pq.push({diff, i}); 
        }

        while(extraStudents > 0) {
            auto [topDiff, i] = pq.top();
            pq.pop();

            classes[i][0]++; classes[i][1]++;
            double totPass = (double) classes[i][0], totStudent = (double) classes[i][1];
            double diff = ((totPass + 1)/(totStudent + 1)) - (totPass/totStudent);
            pq.push({diff, i});
            extraStudents--;
        }

        double tot = 0;
        for(auto& x : classes) {
            tot += (double) x[0] / x[1];
        }

        return tot / classes.size();
        
        
    }
};