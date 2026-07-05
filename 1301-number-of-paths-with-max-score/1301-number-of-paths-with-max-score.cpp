constexpr int mod=1e9+7, N=10000;
using ll=long long;
using int2=pair<int, int>;// (max sum, ways getting max sum)
constexpr int2 None={0, -1};
int2 dp[N];
class Solution {
public:
    static inline int idx(int i, int j, int n){ return i*n+j;}
    static vector<int> pathsWithMaxScore(vector<string>& board) {
        const int n=board.size(), n2=n*n;
        dp[n2-1]={0, 1};
        // last row
        for(int j=n-2, id=n2-2; j>=0; j--, id--){
            const char c=board[n-1][j];
            auto [r0, r1]=dp[id+1];
            dp[id]=(c=='X' || r1==-1)? None : make_pair(r0+c-'0', 1);
        }
        // last column
        for(int i=n-2, id=n2-1-n; i>=0; i--, id-=n){
            const char c=board[i][n-1];
            auto [d0, d1]=dp[id+n];
            dp[id]=(c=='X' || d1==-1)? None : make_pair(d0+c-'0', 1);
        }
        board[0][0]='0';
        for(int i=n-2; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                const int cur=idx(i, j, n), r=cur+1, d=cur+n, s=cur+n+1;
                const int c=board[i][j];
                if (c=='X'){
                    dp[cur]=None;
                    continue;
                }
                auto& [r0, r1]=dp[r];
                auto& [d0, d1]=dp[d];
                auto& [s0, s1]=dp[s];
                int prvM=-1;
                if (r1>0) prvM=max(prvM, r0);
                if (d1>0) prvM=max(prvM, d0);
                if (s1>0) prvM=max(prvM, s0);
                if (prvM==-1) {
                    dp[cur]=None; 
                    continue;
                }
                ll ways=0;
                ways+=(r1>0 && prvM==r0)?r1:0;
                ways+=(d1>0 && prvM==d0)?d1:0;
                ways+=(s1>0 && prvM==s0)?s1:0;
                dp[cur]={prvM+c-'0',  ways%mod};
            }
        }
        auto& [sum, ways]=dp[0];
        return (ways<=0)?vector<int>({0, 0}):vector<int>({sum, ways});
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna