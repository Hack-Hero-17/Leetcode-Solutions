class Solution {
public:
    int solve(int eggs, int floors, vector<vector<int>>& dp){
        if(floors==1 || floors==0 || eggs==1) return floors;
        if(dp[eggs][floors]!=-1) return dp[eggs][floors];

        int low = 1, high = floors;
        int mn = INT_MAX;

        while(low<=high){
            int mid = low + (high - low)/2;
            int broken = solve(eggs-1, mid-1, dp);
            int notBroken = solve(eggs, floors-mid, dp);

            int temp = 1 + max(broken, notBroken);

            mn = min(mn, temp);

            if(broken > notBroken){
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }
        return dp[eggs][floors] = mn;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        return solve(k, n, dp);
    }
};