class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) 
        {
            s.insert(num);
        }
        for (int i = 1; i <= nums.size() + 1; ++i) 
        {
            if (!s.count(i)) 
            {
                return i;
            }
        }
        return -1;
    }
};