class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (k == 1) return n;

        int res = 0;

        for (int i = 0; i <= n - k;) {
            int step = 1;

            for (int d : {k, k + 1}) {
                if (i + d <= n && equal(s.begin() + i, s.begin() + i + (d >> 1),
                                        s.rbegin() + (n - (i + d)))) {
                    step = d;
                    res++;
                    break;
                }
            }

            i += step;
        }

        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna