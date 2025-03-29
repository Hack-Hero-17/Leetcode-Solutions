class Solution {
public:
    int solveUtil ( vector<int>& arr , int ind , vector<int>& dp )
    {

        if( ind < 0 )
            return 0;
        if( dp[ind] != -1 )
            return dp[ind];
        if( ind == 0 )
            return arr[ind];
        

        int pick = arr[ind] + solveUtil( arr , ind-2 , dp);
        int nonpick = 0 + solveUtil( arr , ind-1 , dp);

        return dp[ind] = max(pick , nonpick );
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n ,-1);
        return solveUtil( nums , n-1 , dp );
    }
};