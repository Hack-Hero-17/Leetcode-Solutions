class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;

        auto isDistinct = [&]() {
            for (auto& [k, v] : freq)
                if (v > 1) return false;
            return true;
        };

        if (isDistinct()) return 0;

        int k = 0;
        while (!nums.empty()) {
            if (nums.size() < 3) return k + 1;

            for (int i = 0; i < 3; ++i) {
                freq[nums[i]]--;
                if (freq[nums[i]] == 0) freq.erase(nums[i]);
            }
            nums.erase(nums.begin(), nums.begin() + 3);
            k++;
            if (isDistinct()) return k;
        }

        return k;
    }
};