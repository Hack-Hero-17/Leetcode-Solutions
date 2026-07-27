class Solution {
public:
    int maxProduct(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin()+1, nums.end(), greater<int>());
        return (nums[0]-1)*(nums[1]-1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna