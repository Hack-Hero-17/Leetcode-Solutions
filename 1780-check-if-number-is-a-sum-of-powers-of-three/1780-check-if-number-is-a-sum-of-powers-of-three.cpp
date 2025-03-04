class Solution {
public:
    bool checkPowersOfThree(int n) {
         while (n > 0) {
            if (n % 3 == 2) {
                return false; // If n % 3 is 2, it's not a sum of powers of 3
            }
            n /= 3; // Reduce n by dividing it by 3
        }
        return true;
    }
};