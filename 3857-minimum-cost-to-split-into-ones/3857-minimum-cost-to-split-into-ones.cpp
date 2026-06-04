class Solution {
public:
    int minCost(int n) {

        int cost = 0;
        queue<int> q;

        q.push(n / 2); q.push(n - (n / 2));
        cost = (n / 2) * (n - n / 2);

        while(!q.empty()) {
            int top = q.front();
            q.pop();
            
            int a = top / 2, b = top - top / 2;

            if(a > 1) q.push(a);
            if(b > 1) q.push(b);

            cost += (a * b);
        }

        return cost;
    }
};