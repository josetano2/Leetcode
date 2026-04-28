class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double tot = 0;
        for (auto& x : nums) {
            pq.push(x);
            tot += x;
        }
        priority_queue<double> temp = pq;

        double half = tot / 2.0, curr = 0, count = 0;
        while(!pq.empty() && curr < half) {
            double top = pq.top();
            pq.pop();

            top /= 2.0;
            curr += top;
            pq.push(top);
            count++;
        }

        return count;
    }
};