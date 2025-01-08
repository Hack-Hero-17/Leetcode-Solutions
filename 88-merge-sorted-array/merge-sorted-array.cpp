class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = 0;
        int right = 0;
        vector<int> arr;

        // Merge elements from nums1 and nums2 into arr
        while (left < m && right < n) {
            if (nums1[left] < nums2[right]) {
                arr.push_back(nums1[left]);
                left++;
            } else {
                arr.push_back(nums2[right]);
                right++;
            }
        }

        // Add remaining elements from nums1, if any
        while (left < m) {
            arr.push_back(nums1[left]);
            left++;
        }

        // Add remaining elements from nums2, if any
        while (right < n) {
            arr.push_back(nums2[right]);
            right++;
        }

        // Copy merged elements back to nums1
        for (int i = 0; i < m + n; i++) {
            nums1.at(i) = arr[i];
        }
    }
};
