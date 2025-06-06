class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
    unordered_map<int, int> index;
    vector<vector<int>> dp(n, vector<int>(n, 2));
    int maxLength = 0;

    // Store the index of each number in the array
    for (int i = 0; i < n; i++) {
        index[arr[i]] = i;
    }

    // Iterate through all pairs (i, j)
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < j; i++) {
            int k = index.count(arr[j] - arr[i]) ? index[arr[j] - arr[i]] : -1;
            
            // Ensure the third element (k) is before the second element (i)
            if (k >= 0 && k < i) {
                dp[i][j] = dp[k][i] + 1;
                maxLength = max(maxLength, dp[i][j]);
            }
        }
    }

    return maxLength >= 3 ? maxLength : 0;
    }
};