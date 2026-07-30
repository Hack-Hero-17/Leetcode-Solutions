class Solution {
public:
    int minimumPushes(string A) {
        auto q = A.size() >> 3, r = A.size() & 7;
        return ((q << 2) + r) * (q + 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna