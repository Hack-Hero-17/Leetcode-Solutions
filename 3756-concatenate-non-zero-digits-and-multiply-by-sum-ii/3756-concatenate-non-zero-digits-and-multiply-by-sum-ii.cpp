static constexpr int mod=1e9+7, N=1e5+1;
static int tens[N]={0};
using ll=long long;
// ( (x, exp10), sum )
using int3=pair<pair<ll,int>, ll>;
int3 prefix[N]={};
class Solution {
public:
    static void compute_tens(){
        if (tens[0]) return;
        ll pow10=tens[0]=1;
        for(int i=1; i<N; i++) {
            pow10*=10;
            if(pow10>=mod) pow10%=mod;
            tens[i]=pow10;
        }
    }

    static vector<int> sumAndMultiply(string& s, vector<vector<int>>& queries) {
        const int n=s.size(), qz=queries.size();
        compute_tens();

        ll x=0, sum=0;
        int exp10=0;

        //build prefix
        for(int i=0; i<n; i++){
            int d=s[i]-'0';
            
            x+=((-(d>0) & 9LL)*x+d);
            if (x>mod) x%=mod;
            exp10+=(d>0);
            sum+=d;
            
            prefix[i+1]={{x, exp10},sum};
        }

        vector<int> ans(qz);

        //  queries 
        for(int i=0; i<qz; i++){
            const int l=queries[i][0], r=queries[i][1]+1;

            ll sum=prefix[r].second-prefix[l].second;
            if (sum<0) sum+=mod;

            const auto& [xl, expl]=prefix[l].first;
            const auto& [xr, expr]=prefix[r].first;

            const int dExp=expr-expl;
            
            const ll xlshift=xl*tens[dExp]%mod;
            const ll X=(xr-xlshift+mod)%mod;

            ans[i]=X*sum%mod;
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