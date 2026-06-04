class Solution {
public:
    int minCost(int n) {

        int cost = 0;
        queue<int> q;
        
        q.push(n / 2);
        if(n % 2 == 0) {
            q.push(n / 2);
            cost = (n / 2) * (n / 2);
        }
        else {
            q.push(n / 2 + 1);
            cost = (n / 2) * (n / 2 + 1);
        }

        while(!q.empty()) {
            int top = q.front();
            q.pop();
            
            int a = top / 2, b = top / 2;
            if(top % 2 != 0) b++;

            if(a > 1) q.push(a);
            if(b > 1) q.push(b);

            cost += (a * b);
        }


        return cost;
    }
};