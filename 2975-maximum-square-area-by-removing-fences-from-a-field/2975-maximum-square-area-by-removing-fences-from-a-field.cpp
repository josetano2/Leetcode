class Solution {
public:

    unordered_set<int> generatePossiblePos(int x, vector<int>& fences) {
        unordered_set<int> possible;
        fences.push_back(1);
        fences.push_back(x);

        sort(fences.begin(), fences.end());
        for(int i = 0; i < fences.size(); i++) {
            for(int j = i + 1; j < fences.size(); j++) {
                possible.insert(fences[j] - fences[i]);
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

