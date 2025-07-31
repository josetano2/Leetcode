class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        
        unordered_set<int> res;
        unordered_set<int> curr;

        for(auto x : arr) {
            unordered_set<int> next;
            next.insert(x);
            for(auto i : curr) {
                next.insert(x | i);
            }
            curr = next;
            for(auto i : curr) {
                res.insert(i);
            }
        }

        return res.size();
    }
};