class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = INT_MAX;
        int maxpri = INT_MIN;
        for( int i=0 ; i<n ; i++ ){
            mini = min(mini, prices[i]);
            maxpri = max( maxpri , prices[i] - mini );
        }
        return maxpri;
    }
};