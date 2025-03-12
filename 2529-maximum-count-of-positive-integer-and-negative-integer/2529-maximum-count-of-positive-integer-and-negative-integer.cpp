class Solution {
public:
    int maximumCount(vector<int>& nums) {
        
        int n = nums.size();
        int neg=0;
        int pos=0;
        for( int i=0 ; i<n ; i++ )
        {
            if( nums[i]<0 )
                neg++;
            if( nums[i]>0 )
                pos++;
        }
        return max( pos,neg);
    }
};