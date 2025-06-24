class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int x=0, y=0 , dx=1, dy=0;
        vector<int> res;
        for( int i=0; i<r*c ; i++ ){
            res.push_back( matrix[y][x] );
            matrix[y][x] = -101;
            if( !( x+dx >=0 && x+dx <c && y+dy>=0 && y+dy<r) || matrix[y+dy][x+dx] == -101 ){
                int temp = dx;
                dx = -dy;
                dy = temp;
            }
            x = x+dx;
            y = y+dy;
        }
        return res;
    }
};