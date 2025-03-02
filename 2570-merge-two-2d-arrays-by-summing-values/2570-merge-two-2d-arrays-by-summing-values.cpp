class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> mergedMap;

    // Insert values from nums1
    for (auto& row : nums1) {
        mergedMap[row[0]] += row[1];  // Sum values for the same ID
    }

    // Insert values from nums2
    for (auto& row : nums2) {
        mergedMap[row[0]] += row[1];  // Sum values for the same ID
    }

    // Convert map to vector
    vector<vector<int>> result;
    for (auto& entry : mergedMap) {
        result.push_back({entry.first, entry.second});
    }

    return result;
    }
};