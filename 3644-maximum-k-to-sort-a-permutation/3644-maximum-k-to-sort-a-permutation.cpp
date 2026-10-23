class Solution {
public:
    static int sortPermutation(vector<int>& nums) {
        const unsigned n=nums.size();
        int k0=bit_ceil(n)-1, k=k0;// all bits are set
        for(int i=0; i<n; i++){
            const int x=nums[i];
            k&=(-(x!=i)& x)+(-(x==i));
        }
        return k==k0?0:k;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna