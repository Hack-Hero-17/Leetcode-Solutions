class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int cntLess = 0, cntGr = 0;
        for(auto it : nums){
            if(it < target){
                cntLess++;
            }else if(it > target){
                cntGr++;
            }
        }
        vector<int> sol;
        int n = nums.size() - cntGr - cntLess;
        for(int i = 0; i < n; i++){
            sol.push_back(i + cntLess);
        }
        return sol;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna