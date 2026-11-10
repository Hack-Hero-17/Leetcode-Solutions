class Solution {
public:
    static int climbStairs(int n, vector<int>& costs) {
        int dp[4]={0}, ans=0;
        for(int i=0; i<n; i++){
            const int i0=i&3, cost=costs[i];
            int inc=dp[(i0+3)&3]+1;
            inc=min(inc, dp[(i0+2)&3]+4);
            inc=min(inc, dp[(i0+1)&3]+9);
            dp[i0]=ans=cost+inc;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna