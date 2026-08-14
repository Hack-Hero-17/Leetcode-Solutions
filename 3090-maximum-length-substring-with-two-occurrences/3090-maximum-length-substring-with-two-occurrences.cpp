class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int res = 0;
        for (int left = 0; left < n; ++left) {
            array<int, 26> count{};
            for (int right = left; right < n; ++right) {
                const int index = s[right] - 'a';
                ++count[index];
                if (count[index] > 2) {
                    break;
                }
                res = max(res, right - left + 1);
            }
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna