class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> areaMap; // Stores island label -> size
        int islandId = 2; // Start labeling islands from 2 (since 0 and 1 are already used)
        int maxIsland = 0;
        
        // Directions for 4-way connectivity
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // DFS to mark islands and compute their sizes
        function<int(int, int, int)> dfs = [&](int r, int c, int id) {
            if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != 1) return 0;
            grid[r][c] = id;
            int size = 1;
            for (auto [dr, dc] : directions) {
                size += dfs(r + dr, c + dc, id);
            }
            return size;
        };

        // Step 1: Mark islands and compute their sizes
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    int size = dfs(r, c, islandId);
                    areaMap[islandId++] = size;
                    maxIsland = max(maxIsland, size);
                }
            }
        }

        // Step 2: Check all 0s and find the maximum island possible
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) {
                    unordered_set<int> seenIslands;
                    int newSize = 1; // Changing 0 to 1 contributes +1

                    for (auto [dr, dc] : directions) {
                        int nr = r + dr, nc = c + dc;
                        if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] > 1) {
                            seenIslands.insert(grid[nr][nc]);
                        }
                    }

                    for (int id : seenIslands) {
                        newSize += areaMap[id];
                    }

                    maxIsland = max(maxIsland, newSize);
                }
            }
        }

        return maxIsland;
    }
};