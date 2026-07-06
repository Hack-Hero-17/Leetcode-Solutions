using int2=pair<int, int>;
const int N=1e5+2;
static int2 R[N];
static constexpr int M=1<<9, mask=M-1, bshift=9;
int freq[M];

void radix_sort(int2* nums, int n) {
    int2* buffer=(int2*)alloca(n*sizeof(int2));  // buffer
    int2* in=nums;
    int2* out=buffer;

    // 2 rounds covers 17 bits 
    for (int round=0; round < 2; round++) {
        const int shift=round * bshift;
        memset(freq, 0, sizeof(freq));

        for (int i=0; i<n; i++)
            freq[(in[i].first >> shift) & mask]++;

        partial_sum(freq, freq+M, freq);

        for (int i = n - 1; i >= 0; i--) {
            int x = (in[i].first >> shift) & mask;
            out[--freq[x]] = in[i];
        }

        // Swap pointers for the next round
        swap(in, out);
    }
    //data is currently in buffer. We must copy it back to nums.
    if (in != nums) {
        memcpy(nums, in, n * sizeof(int2));
    }
}
class Solution {
public:
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        const int n=intervals.size();
        int2* I=(int2*)alloca(n*sizeof(int2));
        int i=0;
        for(const auto& ii : intervals){
            const int a=ii[0], b=ii[1];
            I[i++]={a, b};
        }
        radix_sort(I, n);
        auto [a, b]=I[0];
        int cnt=1;
        for(int i=1; i<n; i++){
            auto [c, d]=I[i];
            if (c>a && d>b){
                a=c;
                cnt++;
            }
            b=max(b, d);
        }
        return cnt;
    }
    
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna