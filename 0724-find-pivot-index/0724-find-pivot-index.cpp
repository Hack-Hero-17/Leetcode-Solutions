class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int lSum = 0;
        int rSum = 0;
        int n = nums.size();

        for(int i=0;i<n;i++) rSum += nums[i];

        for(int i=0;i<n;i++){
            rSum -= nums[i];
            if(i != 0){
                lSum += nums[i-1];
            }

            if(lSum == rSum) return i;
        }

        return -1;

    }
};