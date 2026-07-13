class Solution {
public:
    inline static int q[45];
    inline static bool init = []() {
        int n = 0;
        for (int i = 1; i < 10; i++)
            q[n++] = i;

        for (int i = 0; i < n; i++) {
            int d = q[i] % 10;
            if (d < 9) q[n++] = q[i] * 10 + d + 1;
        }

        return 0;
    }();

    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;

        for (auto& x : q)
            if (x >= low && x <= high)
                res.push_back(x);

        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna