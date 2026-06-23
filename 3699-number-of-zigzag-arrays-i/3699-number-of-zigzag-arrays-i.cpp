constexpr int P=1e9+7, N=2000;
using ll=long long;
// dp[x]=count of such seqs s[i]=x where x in [0,.., m-1] with m=r-l+1
static unsigned dp[N]; 
class Solution {
public:
    static int zigZagArrays(int n, int l, int r) {
        const int m=r-l+1;
        fill_n(dp, m, 1);
        tuple<int, int, int> ii[2]={{0, m, 1}, {m-1, -1, -1}};
        for(int i=1; i<n; i++){
            const bool dir=i&1;
            ll Sum=0;
            auto [i0, iN, step]=ii[dir];
            for(int j=i0; j!=iN; j+=step){
                ll x=dp[j];              
                dp[j]=Sum;              
                Sum=(Sum+x)%P;
            }
        }
        return 2*reduce(dp, dp+m, 0LL)%P;
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