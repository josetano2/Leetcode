class Solution {
public:
    vector<vector<int>> spiralMatrix(int height, int width, ListNode* head) {

        ListNode* curr = head;

        vector<vector<int>> ans(height, vector<int>(width, -1));

        int tracker = 0, x = tracker, y = tracker;

        while (curr) {

            if (ans[y][x] != -1) {
                height--;
                width--;
                tracker++;
                x = y = tracker;
            }

            ans[y][x] = curr->val;
            cout << x << " " << y << " " << ans[y][x] << endl;

            if (x < width - 1 && y == tracker) {
                x++;
            } else if (x == width - 1 && y < height - 1) {
                y++;
            } else if (x > tracker && y == height - 1) {
                x--;
            } else if (x == tracker && y > tracker) {
                y--;
            }
            
            curr = curr->next;
        }

        return ans;
    }
};