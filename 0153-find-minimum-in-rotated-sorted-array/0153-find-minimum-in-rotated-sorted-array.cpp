class Solution {
public:
    int findMin(vector<int>& nums) {
        return *partition_point(nums.begin(), nums.end(), [&](int n) { return n > nums.back(); });
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna