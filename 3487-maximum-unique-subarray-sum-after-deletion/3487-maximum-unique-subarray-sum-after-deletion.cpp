class Solution {
public:
    int maxSum(vector<int>& nums) {
    int mx = *max_element(nums.begin(), nums.end());
        // if all elements ≤ 0, best non-empty subarray is the max element
        if (mx <= 0) return mx;
        // track seen positive values
        unordered_set<int> seen;
        int ans = 0;
        for (int x : nums) {
            // include each positive value at most once
            if (x > 0 && !seen.count(x)) {
                ans += x;           // add to sum
                seen.insert(x);     // mark as seen
            }
        }
        return ans;
}
};