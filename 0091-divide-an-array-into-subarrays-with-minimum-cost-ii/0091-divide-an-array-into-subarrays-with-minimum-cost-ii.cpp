1class Solution {
2    long long bitSum[100005];
3    int bitCount[100005];
4public:
5    long long minimumCost(vector<int>& nums, int k, int dist) {
6        int n = nums.size(), targetK = k - 1;
7        vector<int> sorted = nums;
8        sort(sorted.begin(), sorted.end());
9        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
10        int m = sorted.size();
11        memset(bitSum, 0, sizeof(bitSum));
12        memset(bitCount, 0, sizeof(bitCount));
13
14        auto update = [&](int idx, int val, int cnt) {
15            for (; idx <= m; idx += idx & -idx) {
16                bitSum[idx] += val;
17                bitCount[idx] += cnt;
18            }
19        };
20
21        long long minExtra = LLONG_MAX;
22        int maxP = m > 0 ? 1 << (31 - __builtin_clz(m)) : 0;
23        for (int i = 1; i < n; ++i) {
24            int r = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin() + 1;
25            update(r, nums[i], 1);
26            if (i > dist + 1) {
27                int oldV = nums[i - dist - 1];
28                int oldR = lower_bound(sorted.begin(), sorted.end(), oldV) - sorted.begin() + 1;
29                update(oldR, -oldV, -1);
30            }
31            if (i >= targetK) {
32                int idx = 0, cc = 0; long long cs = 0;
33                for (int p = maxP; p > 0; p >>= 1) {
34                    if (idx + p <= m && cc + bitCount[idx + p] < targetK) {
35                        idx += p; cc += bitCount[idx]; cs += bitSum[idx];
36                    }
37                }
38                if (cc < targetK) cs += (long long)(targetK - cc) * sorted[idx];
39                minExtra = min(minExtra, cs);
40            }
41        }
42        return nums[0] + minExtra;
43    }
44};