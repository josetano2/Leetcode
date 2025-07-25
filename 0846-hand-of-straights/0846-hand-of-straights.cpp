class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int len = hand.size();

        if(len % groupSize != 0) return false;

        unordered_map<int, int> uMap;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto x : hand) {
            if(!uMap[x]) {
                pq.push(x);
            } 
            uMap[x]++;
        }

        while(!pq.empty()) {
            int top = pq.top(), idx = 0, curr = top;

            while(idx < groupSize) {
                if(uMap[curr] > 0) {
                    uMap[curr]--;

                    if(uMap[curr] == 0) {
                        pq.pop();
                    }
                    idx++;
                    curr++;
                }
                else{
                    return false;
                }
            }
            cout << top << " ";
        }
        
        return true;

    }
};