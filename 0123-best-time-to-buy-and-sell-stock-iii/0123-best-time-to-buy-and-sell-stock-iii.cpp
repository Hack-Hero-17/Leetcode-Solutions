class Solution {
private:
    int func(vector<int>&prices, int ind, int buy, int count,vector<vector<vector<int>>>& dp){
        int n = prices.size();
        if(count == 0 || ind == n ) return 0;
        if(dp[ind][buy][count] !=-1) return dp[ind][buy][count];
        if(buy){
            return dp[ind][buy][count]  = max(-prices[ind]+ func(prices,ind+1,0,count,dp), func(prices,ind+1,1,count,dp));
       }
        else{
            return dp[ind][buy][count]  = max(prices[ind] + func(prices,ind+1,1,count-1,dp), func(prices,ind+1,0,count,dp));
        }
        return dp[ind][buy][count];
    } 
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(2,vector<int>(3,0)));
        dp[n][0][0] = 0;

        for(int ind = n-1 ; ind >= 0 ; ind-- ){
            for(int buy = 0 ; buy<=1;buy++){
                for(int count = 1;count<=2;count++){
                    if(buy){
                        dp[ind][buy][count]  = max(-prices[ind]+ dp[ind+1][0][count], dp[ind+1][1][count]);
                    }
                    else{
                        dp[ind][buy][count]  = max(prices[ind] + dp[ind+1][1][count-1], dp[ind+1][0][count]); 
                    }
                }
            }
        }



       return dp[0][1][2];
    }
};