// variant
class Solution {
public:
    char findKthBit(int n, int k) {
        if (k==1) return '0';// base case
        int sz=bit_width((unsigned)k);
        int k0=(1<<sz)-k; // reflected number
        if (k0==k) return '1';// k is a symmetry number
        return '1'-(findKthBit(n, k0)=='1');
    }
};