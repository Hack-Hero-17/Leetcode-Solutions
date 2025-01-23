class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size();
    int cols = grid[0].size();
    
    vector<int> rowCount(rows, 0);
    vector<int> colCount(cols, 0);
    
    // Count the number of servers in each row and column
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                rowCount[i]++;
                colCount[j]++;
            }
        }
    }
    
    int result = 0;
    
    // Check each server to see if it can communicate
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1 && (rowCount[i] > 1 || colCount[j] > 1)) {
                result++;
            }
        }
    }
    
    return result;
    }
};