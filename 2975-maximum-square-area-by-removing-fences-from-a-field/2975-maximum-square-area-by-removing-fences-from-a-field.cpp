class Solution {
public:

    unordered_set<int> generatePossiblePos(int x, vector<int>& fences) {
        unordered_set<int> possible;
        possible.insert(x - 1);

        for(int i = 0; i < fences.size(); i++) {
            possible.insert(fences[i] - 1);
            possible.insert(x - fences[i]);
        }

        for(int i = 0; i < fences.size(); i++) {
            for(int j = i + 1; j < fences.size(); j++) {
                possible.insert(abs(fences[j] - fences[i]));
            }
        }

        return possible;
    }

    int maximizeSquareArea(int n, int m, vector<int>& hFences, vector<int>& vFences) {
        
        long long MOD = 1e09+7;
        unordered_set<int> possibleW = generatePossiblePos(m, vFences), possibleH = generatePossiblePos(n, hFences);

        long long area = -1;
        for(auto& x : possibleH) {
            if(possibleW.find(x) != possibleW.end()) if(area < x) area = x;
        }
        return area == -1 ? area : (area * area) % MOD;
    }
};

