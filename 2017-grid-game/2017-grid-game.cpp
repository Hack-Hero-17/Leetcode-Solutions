class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        
        // Calculate prefix sums for the two rows
        vector<long long> topPrefix(n + 1, 0), bottomPrefix(n + 1, 0);
        
        // Compute prefix sum for the first row (top)
        for (int i = 0; i < n; ++i) {
            topPrefix[i + 1] = topPrefix[i] + grid[0][i];
        }
        
        // Compute prefix sum for the second row (bottom)
        for (int i = 0; i < n; ++i) {
            bottomPrefix[i + 1] = bottomPrefix[i] + grid[1][i];
        }
        
        long long minSecondPlayerScore = LLONG_MAX;
        
        // Consider each column as the transition point for the first player
        for (int i = 0; i < n; ++i) {
            // Top remaining sum after column i
            long long topRemaining = topPrefix[n] - topPrefix[i + 1];
            
            // Bottom remaining sum before column i
            long long bottomRemaining = bottomPrefix[i];
            
            // The second player's score is the maximum of the two remaining sums
            long long secondPlayerScore = max(topRemaining, bottomRemaining);
            
            // Minimize the second player's score
            minSecondPlayerScore = min(minSecondPlayerScore, secondPlayerScore);
        }
        
        return minSecondPlayerScore;
    }
};