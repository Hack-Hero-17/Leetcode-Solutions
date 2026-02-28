class Solution {
public:
   #pragma GCC optimize("O3, unroll-loops")
const int mod=1e9+7;
uint64_t dp[100001]={0};
int End=1;
int concatenatedBinary(int n){
    if (n<End) return dp[n];
    uint64_t ans=dp[End-1];// computation from the last end
    for(unsigned x=End; x<=n; x++){
        const int bw=32-__builtin_clz(x);
        ans=(ans<<bw)+x;
        if (ans>=mod) ans%=mod;
        dp[End++]=ans;// store to dp[End], & End++
    }
    return ans;
}
};