class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<int> visited(s.size(), false);
        visited[0] = true;
        int n = s.size(), count = 0;

        for(int i = minJump; i < n; i++) {
            if(visited[i - minJump]) count++;
            if(i - maxJump - 1 >= 0 && visited[i - maxJump - 1]) count--;
            if(count > 0 && s[i] == '0') visited[i] = true;
        }

        return visited[n - 1];
    }
};