class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;
        vector<string> NQueens( n , string(n,'.'));
        solve( n , output , NQueens , 0 );
        return output;
    }
    void solve( int n , vector<vector<string>>& output , vector<string>& NQueens , int row ){
        if( row == n){
            output.push_back(NQueens);
            return;
        }
        for( int col = 0 ; col <n ; col++){
            if( isSafe( n ,NQueens, row , col )){
                NQueens[row][col] = 'Q';
                solve( n , output, NQueens , row+1);
                NQueens[row][col] = '.';
            }
        }
    }
    bool isSafe( int n , vector<string>& NQueens , int row , int col ){
        // int i,j;
        for( int i = 0 ; i<n ; i++ ){
            if( NQueens[i][col] == 'Q' )
                return false;
        }

        for(int  i=row-1 , j = col-1 ; i>=0 && j>=0 ; i-- , j-- ){
            if( NQueens[i][j] == 'Q' )
                return false;
        }

        for(int  i= row-1 ,  j = col+1 ; i>=0 && j<n ; i-- , j++ ){
            if( NQueens[i][j] == 'Q' )
                return false;
        }

        return true;
    }
};