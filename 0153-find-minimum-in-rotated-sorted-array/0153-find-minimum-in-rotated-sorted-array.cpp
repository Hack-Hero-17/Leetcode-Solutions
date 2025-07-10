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
        while( left < right ){
            mid = ( left + right )/2;
            if( arr[left] < arr[mid] ){
                if( arr[mid] > arr[right] ){
                    left = mid+1;
                }else{
                    return arr[left];
                }
            }else{
                if( arr[mid] < arr[right] ){
                    right = mid;
                }
            }
        }
        return arr[left];
    }
};