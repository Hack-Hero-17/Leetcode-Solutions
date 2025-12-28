class Solution {
public:
    /**
     * Count negative numbers in a sorted matrix.
     * Uses binary search on each row to find the first negative.
     *
     * Time Complexity: O(m log n) where m is rows and n is columns
     * Space Complexity: O(1)
     */
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int totalCount = 0;

        // Apply binary search on each row
        for (int row = 0; row < rows; row++) {
            // Binary search template: find first negative (first true)
            int left = 0;
            int right = cols - 1;
            int firstTrueIndex = -1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                // Feasible condition: is this element negative?
                if (grid[row][mid] < 0) {
                    firstTrueIndex = mid;
                    right = mid - 1;  // Search left for earlier negative
                } else {
                    left = mid + 1;  // Search right for negatives
                }
            }

            // If we found a negative, count all elements from that index to end
            if (firstTrueIndex != -1) {
                totalCount += cols - firstTrueIndex;
            }
        }

        return totalCount;
    }
};