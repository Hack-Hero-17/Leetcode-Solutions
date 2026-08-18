class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int length=0;
        for( int i=0; i<nums.size(); i++){
            for( int j=0; j<i; j++){
                if( nums[j] < nums[i] )
                    dp[i] = max(dp[i], dp[j]+1);
            }
            length = max(length, dp[i]);
        }
        return length;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna