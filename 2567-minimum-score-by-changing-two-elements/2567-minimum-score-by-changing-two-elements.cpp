class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        array<int, 3> small, large;
        ranges::partial_sort_copy(nums, small);  // the 3 smallest, ascending
        ranges::partial_sort_copy(nums, large, greater{});  // the 3 largest, descending
        return min({large[0] - small[2], large[1] - small[1], large[2] - small[0]});
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna