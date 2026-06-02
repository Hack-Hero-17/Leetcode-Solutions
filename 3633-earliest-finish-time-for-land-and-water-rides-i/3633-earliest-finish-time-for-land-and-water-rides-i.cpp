class Solution {
public:
    int earliestFinishTime(vector<int>& startL, vector<int>& durL, vector<int>& startW, vector<int>& durW) {
        int minL = 3000, minW = minL, res = minW;
        int n = startL.size(), m = startW.size();

        for (int i = 0; i < n; i++)
            minL = min(minL, startL[i] + durL[i]);

        for (int i = 0; i < m; i++) {
            minW = min(minW, startW[i] + durW[i]);
            res = min(res, max(minL, startW[i]) + durW[i]);
        }

        for (int i = 0; i < n; i++)
            res = min(res, max(minW, startL[i]) + durL[i]);

        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna