class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        // Base condition: if out of bounds or cell is water (0), return 0
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }

        // Collect fish in the current cell
        int fish = grid[i][j];
        grid[i][j] = 0; // Mark as visited by setting the cell to 0

        // Explore all four directions
        fish += dfs(grid, i + 1, j);
        fish += dfs(grid, i - 1, j);
        fish += dfs(grid, i, j + 1);
        fish += dfs(grid, i, j - 1);

        return fish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int maxFish = 0;

        // Traverse the entire grid
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] > 0) { // Start DFS if cell contains fish
                    maxFish = max(maxFish, dfs(grid, i, j));
                }
            }
        }

        return maxFish;
    }
};