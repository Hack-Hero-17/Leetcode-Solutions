class Solution {
public:
    long long coloredCells(int n) {
        return 1LL + 4LL * (1LL * n * (n - 1) / 2);
    }
};