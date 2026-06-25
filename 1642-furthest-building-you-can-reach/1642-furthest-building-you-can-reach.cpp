class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        priority_queue<int> pq;
        int n = h.size();
        for(int i = 0; i < n - 1; i++) {
            int gap = h[i + 1] - h[i];
            if(gap <= 0) continue;

            bricks -= gap;
            pq.push(gap);

            if(bricks < 0) {
                if(ladders == 0) return i;

                bricks += pq.top();
                pq.pop();
                ladders--;
            }
        }

        return n - 1;
    }
};