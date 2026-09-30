class Solution {
public:
    vector<int> maxDepthAfterSplit(auto s) {
        int n = s.size(); vector<int> res(n);
        
        for (int i = 0; i < n; i++)
            res[i] = (i ^ s[i]) & 1;

        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna