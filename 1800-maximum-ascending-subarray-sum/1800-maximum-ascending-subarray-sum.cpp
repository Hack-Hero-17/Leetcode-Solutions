class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = nums[0]; // Initialize max sum
    int currentSum = nums[0]; // Track current sum
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1]) {
            currentSum += nums[i]; // Add to the current subarray sum
        } else {
            maxSum = max(maxSum, currentSum); // Update max sum if needed
            currentSum = nums[i]; // Start a new subarray
        }
    }
    
    return max(maxSum, currentSum);
    }
};