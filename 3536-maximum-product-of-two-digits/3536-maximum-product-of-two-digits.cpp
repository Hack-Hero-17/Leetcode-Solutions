class Solution {
public:
    int maxProduct(int n) {
        int max1 = 0, max2 = 0;

        for (; n; n /= 10) {
            int d = n % 10;
            if (d >= max1) {
                max2 = max1;
                max1 = d;
            } else if (d > max2) 
                max2 = d;
        }

        return max1 * max2;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna