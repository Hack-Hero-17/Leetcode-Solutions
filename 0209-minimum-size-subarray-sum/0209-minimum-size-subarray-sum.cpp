class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int minlen = INT_MAX;
        int currsum = 0;
        for( int right = 0; right < nums.size() ; right ++){
            currsum += nums[right];
            
            while( currsum >= target ){
                if( right-left+1 < minlen )
                    minlen = right-left+1;
                currsum -= nums[left];
                left++;
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};