class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int sum=0;
        
        // Using binaryS to find the number i_max
        vector<int> col0(n);
        for(int i=0; i<n; i++) col0[i]=grid[i][0];
        int i_max=upper_bound(col0.begin(),col0.end(),0,greater<int>())-col0.begin(); 
    //    cout<<"i_max="<<i_max<<endl;
        ////////////////////
        for (int i=0; i<i_max; i++){
            sum+= m-(upper_bound(grid[i].begin(),grid[i].end(),0,greater<int>())-grid[i].begin());
        }
        sum+=(n-i_max)*m;
        return sum;
    }
};