#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canRob(vector<int>& nums, int k, int maxValue) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= maxValue) {
                count++; // Rob this house
                i++;     // Skip next house (avoid adjacency)
            }
        }
        return count >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canRob(nums, k, mid)) {
                ans = mid;  // Try minimizing maxValue
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};