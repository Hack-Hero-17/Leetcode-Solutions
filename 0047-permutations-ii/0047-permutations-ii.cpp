class Solution {
public:
    void permuteHelper( vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, vector<bool>& used){
        if( ds.size() == nums.size() )
            ans.push_back( ds );
        for( int i=0 ; i<nums.size() ; i++ ){
            if( used[i] ) continue;
        
            if( i>0 && nums[i] == nums[i-1] && !used[i-1] ) continue;

            used[i] = true;
            ds.push_back( nums[i] );
            permuteHelper( nums , ds , ans, used );
            used[i] = false;
            ds.pop_back();
        }


    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> used( nums.size() , false );
        sort( nums.begin() , nums.end() );
        permuteHelper( nums , ds , ans , used );
        return ans;
    }
};