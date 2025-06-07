class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;
        backtrack( 1, comb , res, n ,k );
        return res;
    }
    void backtrack( int num , vector<int> &comb, vector<vector<int>>& res , int n , int k ){
        if( comb.size() == k ){
            res.push_back(comb);
            return;
        }

        for( int start = num ; start<=n ; start++ ){
            comb.push_back(start);
            backtrack( start+1, comb, res, n , k);
            comb.pop_back();
        }
    }
};