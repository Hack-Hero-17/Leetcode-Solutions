1class Solution {
2public:
3        vector<int> minBitwiseArray(vector<int>& nums) {
4        for (int& n : nums) {
5            n = n ^ (((n + 1) & ~n) >> 1) | ((n & 1) - 1);
6        }
7        return move(nums);
8    }
9};