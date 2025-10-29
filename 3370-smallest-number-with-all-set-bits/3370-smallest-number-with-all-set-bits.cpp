class Solution {
public:
    int smallestNumber(unsigned n) {
        int x=1023, prev;
        for(; x>=n; x>>=1)
            prev=x;
        return prev;
    }
};