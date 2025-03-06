class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long int m = grid.size();
        long long int n = m*m;
        long long int sn = ( n*(n+1) ) /2;
        long long int s2n = ( n*(n+1)*(2*n+1) )/6;

        long long int s =0  , s2 = 0;

        for( int i=0 ; i<m ; i++ )
        {
            for( int j=0 ; j<m ; j++ )
            {
            s += (long long)grid[i][j];
            s2 += (long long)grid[i][j] * (long long)grid[i][j];
            }
        }

        int val1 = s - sn;
        int val2 = s2 - s2n;

        val2 = val2/val1;

        int x = ( val1 + val2 )/2;
        int y = x - val1;

        return { x , y };
    }
};