const int N=64, mask=63, bshift=6;
int freq[N];

void radix_sort(int* nums, int n) {
    int* output = (int*)alloca(n * sizeof(int));  // buffer
    unsigned M=*max_element(nums, nums+n);
    const int Mround = max(1, int(31-countl_zero(M)+bshift)/bshift);
    int* in=nums;
    int* out=output;
    bool swapped=0;

    for (int round=0; round<Mround; round++) {
        const int shift=round*bshift;
        memset(freq, 0, sizeof(freq));

        for (int i = 0; i < n; i++)
            freq[(in[i] >> shift) & mask]++;

        partial_sum(freq, freq+N, freq);

        for (int i = n - 1; i >= 0; i--) {
            uint64_t val = in[i];
            uint64_t x = (val >> shift) & mask;
            out[--freq[x]] = val;
        }

        swap(in, out);
        swapped = !swapped;
    }

    // If needed, copy back
    if (swapped)
        memcpy(nums, in, n * sizeof(int));
}
class Solution {
public:
    static int minimumDifference(vector<int>& nums, int k) {
        const int n=nums.size();
        if (k==1) return 0; 
        int* nums_=nums.data();
        radix_sort(nums_, n);
        int diff=INT_MAX;
        for(int l=0, r=k-1; r<n; r++, l++){
            diff=min(diff, nums_[r]-nums_[l]);
        }
        return diff;
    }
};