class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int minWhite = k; // Maximum white blocks we may need to change is K
        int whiteCount = 0;

        // Count initial 'W' in the first window of size k
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') whiteCount++;
        }

        minWhite = whiteCount;

        // Slide the window across the string
        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i - k] == 'W') whiteCount--; // Remove leftmost block
            if (blocks[i] == 'W') whiteCount++; // Add new rightmost block

            minWhite = min(minWhite, whiteCount);
        }

        return minWhite;
    }
};