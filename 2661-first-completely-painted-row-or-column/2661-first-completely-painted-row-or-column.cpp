class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Map to store the position of each value in the matrix
        std::unordered_map<int, std::pair<int, int>> valuePosition;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                valuePosition[mat[i][j]] = {i, j};
            }
        }
        
        // Arrays to count painted cells in each row and column
        std::vector<int> rowCount(m, 0);
        std::vector<int> colCount(n, 0);
        
        // Process each value in arr
        for (int k = 0; k < arr.size(); ++k) {
            auto [i, j] = valuePosition[arr[k]];
            rowCount[i]++;
            colCount[j]++;
            
            // Check if entire row or column is painted
            if (rowCount[i] == n || colCount[j] == m) {
                return k;
            }
        }
        
        return -1; 
    }
};