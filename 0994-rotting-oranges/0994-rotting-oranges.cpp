class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> rotten;

        if( grid.empty() ) return 0;
        int tot=0;
        int days=0;
        int cnt=0;

        for( int i=0; i<grid.size(); i++){
            for( int j=0; j<grid[0].size() ; j++) {
                if( grid[i][j] == 2 ){
                    rotten.push( { i, j } );
                }
                if( grid[i][j] != 0)
                    tot++;
            }
        }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
        while( !rotten.empty()){
            int k = rotten.size();
            cnt += k;
            while(k--){
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();
                
                for( int i=0; i< 4; i++){
                    int m = x + dx[i];
                    int n = y + dy[i];
                    if( m<0 || n<0 || m>=grid.size() || n>=grid[0].size() || grid[m][n] !=1 ){
                        continue;
                    }
                    grid[m][n] = 2;
                    rotten.push({m,n});
                }
            }
            if( !rotten.empty() )
                days++;
        }
        
    return tot == cnt ? days : -1;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna