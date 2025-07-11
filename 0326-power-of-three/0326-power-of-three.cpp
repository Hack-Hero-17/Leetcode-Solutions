class Solution {
public:
    bool isPowerOfThree(int n) {
        double temp = (double) n;
        while( temp > 1 ){
            temp = temp/3.00;
        }
        return temp == 1;
    }
};