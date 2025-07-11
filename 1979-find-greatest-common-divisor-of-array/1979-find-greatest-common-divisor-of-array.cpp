class Solution {
public:
    int findGCD(vector<int>& nums) {

        int min = INT_MAX;
        int max = INT_MIN;
        for(int i= 0;i<nums.size();i++){
            if(nums[i] < min){
                min = nums[i];
            }
            if(nums[i] > max){
                max = nums[i];
            }
        }
        while(max>0 && min>0){
            if(max>min){
                max = max-min;
            }
            else{
                min = min - max;
            }
        }
        return min ==0 ? max :min;
    }
};