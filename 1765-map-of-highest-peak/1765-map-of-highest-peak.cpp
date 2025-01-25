class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
    int n = isWater[0].size();
    
    // Directions for moving up, down, left, right
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    // Initialize the grid and queue
    vector<vector<int>> heights(m, vector<int>(n, -1));
    queue<pair<int, int>> q;

    // Add all water cells to the queue and mark them as height 0
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (isWater[i][j] == 1) {
                heights[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    // Perform BFS
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            // If the neighboring cell is unvisited
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && heights[nx][ny] == -1) {
                heights[nx][ny] = heights[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return heights;
    }
};