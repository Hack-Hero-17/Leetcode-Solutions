using int2=pair<int, int>;
const int N=1e5+2;
static int2 R[N];
class Solution {
public:
    static int maxBuilding(int n, vector<vector<int>>& restrictions) {
        int m=restrictions.size();
        for(int i=0; i<m; i++)
            R[i]={restrictions[i][0], restrictions[i][1]};
        R[m]={1, 0};
        R[m+1]={n, n-1};
        m+=2;
        sort(R, R+m);
              
        for(int i=1; i<m; i++)
            R[i].second=min(R[i].second, R[i-1].second-R[i-1].first+R[i].first);
        int ans=0;
        for(int i=m-2; i>=0; i--){
            R[i].second=min(R[i].second, R[i+1].second+R[i+1].first-R[i].first); 
            int peak=(R[i].second+R[i+1].second+R[i+1].first-R[i].first)/2;
            ans=max(ans, peak);
        }
        return ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna