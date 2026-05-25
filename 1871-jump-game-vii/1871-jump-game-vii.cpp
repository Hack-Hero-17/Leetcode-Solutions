class Solution {
public:
    bool canReach(string s, int minJ, int maxJ) {
        int n = s.length();

        if (s.back() & 1) return false;

        s[0] = 'v';
        int reach = 0, maxR = maxJ;

        for (int i = minJ; i < n; i++) {
            if (i > maxR) return false;

            reach += s[i - minJ] == 'v';
            reach -= (i > maxJ) && s[i - maxJ - 1] == 'v';

            if (reach && (~s[i] & 1)) {
                s[i] = 'v';
                maxR = i + maxJ;
            }
        }

        return reach;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna