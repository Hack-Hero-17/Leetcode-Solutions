class Solution {
public:
    int solve ( vector<int>& arr , int ind , vector<int>& dp )
    {

        if( ind < 0 )
            return 0;
        if( dp[ind] != -1 )
            return dp[ind];
        if( ind == 0 )
            return arr[ind];
        

        int pick = arr[ind] + solve( arr , ind-2 , dp);
        int nonpick = 0 + solve( arr , ind-1 , dp);

        return dp[ind] = max(pick , nonpick );
    }
    int rob(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp1(n-1,-1);
        vector<int> dp2(n-1,-1);
        vector<int> arr1;
        vector<int> arr2;
        
        if(n==1)
            return arr[0];
        
        for(int i=0; i<n; i++){
            
            if(i!=0) arr1.push_back(arr[i]);
            if(i!=n-1) arr2.push_back(arr[i]);
        }
        
        long long int ans1 = solve(arr1 , n-2 , dp1 );
        long long int ans2 = solve(arr2, n-2 , dp2);
        
        return max(ans1,ans2);
    }
};