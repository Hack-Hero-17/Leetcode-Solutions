class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
         long long n = nums.size();
        long long total_pairs = (n * (n - 1)) / 2;
        unordered_map<int, long long> freq;
        long long good_pairs = 0;

        for (int i = 0; i < n; ++i) {
            int key = nums[i] - i;
            if (freq.find(key) != freq.end()) {
                good_pairs += freq[key]; // Count how many times this value appeared before
            }
            freq[key]++;
        }

        return total_pairs - good_pairs;
    }
};