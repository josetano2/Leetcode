class Solution {
public:
    int maximizeSquareArea(int n, int m, vector<int>& hFences, vector<int>& vFences) {
        
        long long MOD = 1e09+7;
        unordered_set<int> possibleW, possibleH;
        possibleH.insert(n - 1);
        possibleW.insert(m - 1); 

        for(int i = 0; i < hFences.size(); i++) {
            possibleH.insert(hFences[i] - 1);
            possibleH.insert(n - hFences[i]);
        }

        for(int i = 0; i < vFences.size(); i++) {
            possibleW.insert(vFences[i] - 1);
            possibleW.insert(m - vFences[i]);
        }

        for(int i = 0; i < hFences.size(); i++) {
            for(int j = i + 1; j < hFences.size(); j++) {
                possibleH.insert(abs(hFences[j] - hFences[i]));
            }
        }

        for(int i = 0; i < vFences.size(); i++) {
            for(int j = i + 1; j < vFences.size(); j++) {
                possibleW.insert(abs(vFences[j] - vFences[i]));
            }
        }
        

        long long area = -1;
        for(auto& x : possibleH) {
            if(possibleW.find(x) != possibleW.end()) {
                if(area < x) area = x;
            }
        }

        return area == -1 ? area : (area * area) % MOD;
    }
};

