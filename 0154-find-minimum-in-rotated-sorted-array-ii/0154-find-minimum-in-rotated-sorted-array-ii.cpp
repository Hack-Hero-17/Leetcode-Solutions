class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() - 1;
        int last = nums[n];
        int left = 0, right = n;

        while (left < n && nums[left] == last)
            left++;

        while (left < right) { // Fixed operator precedence: compute mid as average of left and right
            // Removed stray characters that caused compilation errors
            int mid = left + ((right - left) >> 1);

            if (nums[mid] > last)
                left = mid + 1;
            else
                right = mid;
        }

        return nums[left];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna