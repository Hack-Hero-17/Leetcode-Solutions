#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<long long>> dp;

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Step 1: Sort robots
        sort(robot.begin(), robot.end());

        // Step 2: Sort factories by position
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        // Step 3: Initialize DP
        dp.assign(n, vector<long long>(m, -1));

        // Step 4: Start recursion
        return solve(0, 0, robot, factory);
    }

    long long solve(int i, int j, vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();

        // All robots assigned
        if (i == n) return 0;

        // No factories left
        if (j == m) return 1e15;

        // Memoization
        if (dp[i][j] != -1) return dp[i][j];

        // Option 1: Skip factory
        long long res = solve(i, j + 1, robot, factory);

        long long cost = 0;
        int pos = factory[j][0];
        int limit = factory[j][1];

        // Option 2: Assign k robots
        for (int k = 0; k < limit && (i + k) < n; k++) {
            cost += abs(robot[i + k] - pos);
            res = min(res, cost + solve(i + k + 1, j + 1, robot, factory));
        }

        return dp[i][j] = res;
    }
};