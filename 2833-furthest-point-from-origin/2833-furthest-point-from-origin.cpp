class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        unordered_map<char, int> um;
        for(auto& m : moves) um[m]++;
        return abs(um['R'] - um['L']) + um['_'];
    }
};