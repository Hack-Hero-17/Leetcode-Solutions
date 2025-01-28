class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = nums.size();

        // Create a vector of pairs (value, index) and sort it by value
        vector<pair<int, int>> elements;
        for (int i = 0; i < n; ++i) {
            elements.emplace_back(nums[i], i);
        }
        sort(elements.begin(), elements.end());

        long long operations = n; // Base operations to remove elements
        for (int i = 1; i < n; ++i) {
            if (elements[i].second < elements[i - 1].second) {
                // Add operations if the current index is less than the previous index
                operations += n - i;
            }
        }

        return operations;
    }
};