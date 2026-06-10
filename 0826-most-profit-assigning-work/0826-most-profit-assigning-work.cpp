class Job {
public:
    int diff;
    int profit;

    Job(int diff, int profit) {
        this->diff = diff;
        this->profit = profit;
    }
};

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        vector<Job> jobs;
        for(int i = 0; i < difficulty.size(); i++) jobs.push_back(Job(difficulty[i], profit[i]));

        sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
            return a.profit > b.profit;
        });

        int ans = 0;
        for(auto& w : worker) {
            for(auto& j : jobs) {
                if(w >= j.diff) {
                    ans += j.profit; break;
                }
            }
        }

        return ans;
    }
};