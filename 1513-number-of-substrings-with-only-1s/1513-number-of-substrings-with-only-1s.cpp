class Solution {
public:
    const long long mod=1e9+7;
    int numSub(string& s) {
        long long count=0;
        long long ans=0;
        for(char c: s){
            const bool is0=c=='0';
            ans+=(-is0 & count*(count+1)/2);
            ans%=mod;
            count=(-!is0 & count+1);
        }
        ans=(ans+(long long)count*(count+1)/2%mod);// last one
        return ans;
    }
};