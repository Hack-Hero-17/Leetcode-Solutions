class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int left = binarySearch( nums , target , true );
        int right = binarySearch( nums , target , false );
        res.push_back(left);
        res.push_back(right);
        return res;
    }
    int binarySearch( vector<int>& nums, int target , bool isLeftSearch ){
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        int idx = -1;
        while( left <= right ){
            mid = (left + right)/2;
            if( nums[mid] < target )
                left = mid+1;
            else if( nums[mid] > target )
                right = mid-1;
            else{
                idx = mid;
                if(isLeftSearch)
                    right = mid-1;
                else
                    left = mid+1;
            }
        }
        return idx;
    }
};