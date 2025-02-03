class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;

    int maxLength = 1;
    int incLength = 1;
    int decLength = 1;

    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] > nums[i - 1]) {
            incLength++;
            decLength = 1;
        } else if (nums[i] < nums[i - 1]) {
            decLength++;
            incLength = 1;
        } else {
            incLength = 1;
            decLength = 1;
        }
        maxLength = std::max(maxLength, std::max(incLength, decLength));
    }

    return maxLength;
    }
};