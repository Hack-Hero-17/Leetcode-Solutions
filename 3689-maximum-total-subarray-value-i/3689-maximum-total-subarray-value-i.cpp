class Solution {
public:
    long long maxTotalValue(vector<int>& A, int k) {
        int gMin = A.front(), gMax = A.front();

        for (auto& n : A) {
            gMin = min(gMin, n);
            gMax = max(gMax, n);
        }
        
        return (long long)(gMax - gMin) * k;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna