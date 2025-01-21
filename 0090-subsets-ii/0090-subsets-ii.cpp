class Solution {
public:
     void fun(vector<int>& nums, int index, vector<int>& ds, set<vector<int>>& res) {
        if (index == nums.size()) {
            res.insert(ds); // Insert the current subset
            return;
        }
        
        // Include the current element
        ds.push_back(nums[index]);
        fun(nums, index + 1, ds, res);
        ds.pop_back(); // Backtrack
        
        // Skip duplicates: only process the next element if it's different from the current one
        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
            index++;
        }
        
        // Do not include the current element
        fun(nums, index + 1, ds, res);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the input array to handle duplicates correctly
        vector<int> ds;
        set<vector<int>> res;
        vector<vector<int>> ans;
        
        fun(nums, 0, ds, res);
        
        // Convert the set to a vector
        for (auto& subset : res) {
            ans.push_back(subset);
        }
        
        return ans;
    }
};