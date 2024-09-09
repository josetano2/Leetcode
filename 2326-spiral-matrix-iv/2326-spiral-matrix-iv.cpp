class Solution {
public:
    vector<vector<int>> spiralMatrix(int height, int width, ListNode* head) {
        vector<vector<int>> ans(height, vector<int>(width, -1));

        int top = 0, bottom = height - 1;
        int left = 0, right = width - 1;
        int x = 0, y = 0;

        ListNode* curr = head;

        // Directions: right, down, left, up
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0; // Start by moving right

        while (curr) {
            ans[x][y] = curr->val;
            curr = curr->next;

            int next_x = x + directions[dir].first;
            int next_y = y + directions[dir].second;

            // Check if we need to change direction
            if (next_x < top || next_x > bottom || next_y < left || next_y > right || ans[next_x][next_y] != -1) {
                // Adjust boundaries after completing a side
                if (dir == 0) top++;        // Moving right
                else if (dir == 1) right--; // Moving down
                else if (dir == 2) bottom--; // Moving left
                else if (dir == 3) left++;   // Moving up

                // Change direction (right -> down -> left -> up -> right...)
                dir = (dir + 1) % 4;

                // Update to new direction
                next_x = x + directions[dir].first;
                next_y = y + directions[dir].second;
            }

            // Move to the next cell
            x = next_x;
            y = next_y;
        }

        return ans;
    }
};
