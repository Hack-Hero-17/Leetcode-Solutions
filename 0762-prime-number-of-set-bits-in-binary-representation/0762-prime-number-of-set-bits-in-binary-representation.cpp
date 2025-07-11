class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        while(left <= right){            
            cnt += 665772 >> __builtin_popcount(left++) & 1;
        }

        return cnt;
    }
};