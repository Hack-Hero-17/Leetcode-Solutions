#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canDistribute(vector<int>& candies, long long k, long long mid) {
        long long count = 0;
        for (int c : candies) {
            count += c / mid;  // Count how many children can be served
            if (count >= k) return true;  // Stop early if we already met the requirement
        }
        return count >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long totalCandies = 0;
        for (int c : candies) totalCandies += c;
        if (totalCandies < k) return 0;  // If we can't give at least 1 candy per child, return 0

        int left = 1, right = *max_element(candies.begin(), candies.end());
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(candies, k, mid)) {
                result = mid;  // Update result and try for more candies
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};
