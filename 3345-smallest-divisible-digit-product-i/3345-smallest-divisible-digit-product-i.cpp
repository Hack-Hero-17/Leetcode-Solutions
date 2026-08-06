class Solution {
public:
    int smallestNumber(int n, int t) {
        auto [q, r] = div(n, 10);

        int req = t / gcd(q + (10 - q) / 10, t);
        int nxt = ((r + req - 1) / req) * req;
        int x = nxt - (nxt - 10) * (nxt / 10);

        return q * 10 + x;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna