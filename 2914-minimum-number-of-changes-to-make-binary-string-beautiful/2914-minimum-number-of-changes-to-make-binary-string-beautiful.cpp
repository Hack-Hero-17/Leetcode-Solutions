class Solution {
public:
    int minChanges(string s) {
        return ranges::count_if(s | views::chunk(2), [](auto pair) { return pair[0] != pair[1]; });
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna