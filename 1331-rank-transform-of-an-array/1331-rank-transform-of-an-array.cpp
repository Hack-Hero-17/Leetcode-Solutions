class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> s = arr;
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = lower_bound(s.begin(), s.end(), arr[i]) - s.begin() + 1;
        }
        return arr;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna