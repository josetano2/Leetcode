class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<pair<int, int>> stk;

        for (int i = 0; i < asteroids.size(); i++) {

            if (asteroids[i] > 0) {
                stk.push({asteroids[i], i});
                continue;
            }

            if (asteroids[i] < 0) {
                while (!stk.empty()) {
                    if (stk.top().first > (asteroids[i] * -1)) {
                        // curr explode
                        asteroids[i] = 0;
                        break;
                    } else if (stk.top().first == (asteroids[i] * -1)) {
                        // both explode
                        asteroids[i] = 0;
                        asteroids[stk.top().second] = 0;
                        stk.pop();
                        break;
                    } else {
                        // top stack explode
                        asteroids[stk.top().second] = 0;
                        stk.pop();
                    }
                }
            }
        }

        asteroids.erase(
            remove(asteroids.begin(), asteroids.end(), 0),
            asteroids.end()
        );

        return asteroids;
    }
};