class Solution {
public:
    int solve( int i , int j , int m , vector<vector<int>>& dp , vector<vector<int>>& mat )
    {
        if( dp[i][j] != -1 )
            return dp[i][j];
        if( i==m-1 )
            return mat[i][j];
        
        int down = mat[i][j] + solve( i+1 , j , m , dp , mat );
        int right = mat[i][j] + solve( i+1 , j+1 , m , dp , mat );

        return dp[i][j] = min( down , right );
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp( m , vector<int>( m , -1 ) );

        return solve( 0 , 0 , m , dp , triangle );
    }
};