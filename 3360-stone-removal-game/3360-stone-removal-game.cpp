class Solution {
public:
    bool canAliceWin(auto n) {
        int m = sqrt(433 - 8 * n) - 1;
        return ~m & 2;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna