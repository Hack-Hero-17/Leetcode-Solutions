class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int el;
        for( int i=0 ; i<nums.size() ; i++ ){
            if( cnt == 0 ){
                cnt++;
                el = nums[i];
            }
            else if( el == nums[i] ) cnt++;
            else cnt--;
        }
        return el;
    }
};