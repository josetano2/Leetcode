class Solution {
public:

    vector<int> parent;

    int find(int i) {
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int irep = find(i), jrep = find(j);
        parent[irep] = jrep;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        
        for(int i = 0; i < source.size(); i++) parent.push_back(i);
        
        for(auto& x : allowedSwaps) unite(x[0], x[1]);

        unordered_map<int, vector<int>> um;
        for(int i = 0; i < parent.size(); i++) um[find(i)].push_back(i);
        

        int hamming = 0;
        for(auto& [root, idxs] : um) {
            unordered_map<int, int> freqS, freqT;
            for(int i = 0; i < idxs.size(); i++) {
                freqS[source[idxs[i]]]++;
                freqT[target[idxs[i]]]++;
            }

            int curr = 0;
            for(auto& [v, freq] : freqS) curr += min(freqS[v], freqT[v]);

            hamming += idxs.size() - curr;
        }

        return hamming;
    }
};