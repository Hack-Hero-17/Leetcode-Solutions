class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (-target <= nums[i] - nums[j] &&
                    nums[i] - nums[j] <= target) {
                    if (dp[j] > -1) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
        }
        return dp[n - 1];
    }
};