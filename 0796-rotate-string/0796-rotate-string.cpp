class Solution {
public:
    bool rotateString(string s, string goal) {
        s = s + s;
        return s.contains(goal) && (s.size() / 2) == goal.size();
    }
};