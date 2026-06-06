class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        const int n=nums.size();
        vector<int> ans(n);
        int lsum=0, rsum=accumulate(nums.begin(), nums.end(), 0);
        for(int i=0; i<n; i++){
            const int x=nums[i];
            rsum-=x;
            ans[i]=(rsum>=lsum)?rsum-lsum:lsum-rsum;
            lsum+=x;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna