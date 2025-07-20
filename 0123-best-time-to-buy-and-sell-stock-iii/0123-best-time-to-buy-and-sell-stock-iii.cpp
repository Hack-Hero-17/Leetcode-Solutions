int dp_SO(vector<int>& prices) {
    int n = prices.size();
    
    // Only need previous day's values: [state][capacity]
    vector<vector<int>> prev(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));
    
    for(int day = n-1; day >= 0; day--) {
        // Base case for 0 capacity
        curr[0][0] = curr[1][0] = 0;
        
        for(int cap = 1; cap < 3; cap++) {
            // Buy state profit
            int buyProfit = max(-prices[day] + prev[0][cap], prev[1][cap]);
            
            // Sell state profit (decrement capacity)
            int sellProfit = max(prices[day] + prev[1][cap-1], prev[0][cap]);
            
            curr[1][cap] = buyProfit;   // Buy state
            curr[0][cap] = sellProfit;  // Sell state
        }
        
        prev.swap(curr);  // Move to next iteration
    }
    
    return prev[1][2];  // Start in buy state with max capacity
}