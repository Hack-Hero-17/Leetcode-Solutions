class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int top = m, down = -1, left = n, right = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    top = min(top, i);
                    down = max(down, i);
                    left = min(left, j);
                    right = max(right, j);
                }
            }
        }
        return (down - top + 1) * (right - left + 1);
    }
};