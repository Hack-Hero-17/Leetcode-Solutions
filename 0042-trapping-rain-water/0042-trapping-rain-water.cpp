class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() -1;
        int leftM = height[left];
        int rightM = height[right];
        int water = 0;
        while( left < right ){
            if( leftM < rightM ){
                left++;
                leftM = max(leftM, height[left]);
                water += leftM - height[left];
            }
            else{
                right--;
                rightM = max(rightM, height[right]);
                water += rightM - height[right];
            }
        }
        return water;
    }
};