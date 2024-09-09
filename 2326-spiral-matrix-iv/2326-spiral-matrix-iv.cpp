class Solution {
public:
    vector<vector<int>> spiralMatrix(int height, int width, ListNode* head) {
        ListNode* curr = head;
        vector<vector<int>> ans(height, vector<int>(width, -1));
        int tracker = 0, x = tracker, y = tracker;
        while (curr) {
            ans[y][x] = curr->val;
            curr = curr->next;
            if (x < width - 1 && y == tracker) {
                x++;
            } else if (x == width - 1 && y < height - 1) {
                y++;
            } else if (x > tracker && y == height - 1) {
                x--;
            } else if (x == tracker && y > tracker) {
                y--;
            }
            if (ans[y][x] != -1) {
                height--;
                width--;
                tracker++;
                x = y = tracker;
            }   
        }
        return ans;
    }
};