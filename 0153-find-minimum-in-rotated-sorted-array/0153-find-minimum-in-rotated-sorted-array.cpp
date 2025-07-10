class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = solveUtil( nums );
        return min;
    }
    int solveUtil( vector<int>& arr ){
        int left , right, mid;
        left = 0;
        right = arr.size() - 1;
        while( left <= right ){
            mid = ( left + right )/2;
            if( arr[mid] <= arr[right] )
                right = mid;
            else
                left = mid+1;
        }
        return arr[left];
    }
};