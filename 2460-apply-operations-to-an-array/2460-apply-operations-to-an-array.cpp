class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
    
    // Step 1: Apply operations
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }
    
    // Step 2: Shift all zeroes to the end
    int insertPos = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[insertPos]);
            insertPos++;
        }
    }
    
    return nums;
    }
};