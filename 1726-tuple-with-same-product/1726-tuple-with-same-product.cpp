class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
         unordered_map<int, int> productCount;
    int n = nums.size();
    int result = 0;

    // Count frequency of each product
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int product = nums[i] * nums[j];
            productCount[product]++;
        }
    }

    // Calculate valid tuples
    for (auto& entry : productCount) {
        int freq = entry.second;
        if (freq > 1) {
            result += (freq * (freq - 1) / 2) * 8;  // Each pair contributes 8 permutations
        }
    }

    return result;
    }
};