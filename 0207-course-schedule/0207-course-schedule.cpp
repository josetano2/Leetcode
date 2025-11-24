class Solution {
public:

    bool dfs(vector<vector<int>>& graph, vector<int>& state, int course) {
        if(state[course] == 1) return false;
        if(state[course] == 2) return true;

        state[course] = 1;
        for(auto& neighbor : graph[course]) {
            if(!dfs(graph, state, neighbor)) return false;
        }
        state[course] = 2;
        return true;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        if(prerequisites.size() == 0) return true;
        vector<vector<int>> graph(numCourses);
        vector<int> state(numCourses, 0);

        for(auto& p : prerequisites) {
            int todo = p[0];
            int pre = p[1];
            graph[pre].push_back(todo);
        }

        for(int i = 0; i < numCourses; i++) {
            if(state[i] == 0) {
                if(!dfs(graph, state, i)) return false;
            }
        }

        return true;
    }
};