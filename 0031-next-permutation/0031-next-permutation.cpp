class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<vector<int>> ans;
        helper( nums , ans , 0 );
    }
    void helper( vector<int> & nums , vector<vector<int>> & ans , int start ){
        if( start == nums.size() -1  )
            ans.push_back(nums);
        if( ans.size() == 2 )
            return;
        for( int i= start ; i<nums.size() ; i++ )
        {
            swap( nums[start] , nums[i] );
            helper( nums , ans , start+1 );
            swap( nums[start] , nums[i] );
        }
    }
};