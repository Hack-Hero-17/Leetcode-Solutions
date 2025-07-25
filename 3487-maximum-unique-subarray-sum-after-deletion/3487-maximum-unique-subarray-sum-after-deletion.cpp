class Solution {
public:
    int maxSum(vector<int>& nums) {
        int mx = * max_element( nums.begin() , nums.end() );
        if( max <= 0 ){
            return mx;
        }
        unordered_set<int> seen;
        int ans =0 ;
        for( int x : nums ){
            if( x<= 0 || seen.count(x) ){
                continue;
            }
            ans += x;
            seen.insert(x);
        }
        return ans;
    }
};