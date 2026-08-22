class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int digitSum = 0;
        long long digitProduct = 1;
        while( n > 0 ){
            int digit = n %10;
            digitSum += digit;
            digitProduct *= digit;
            n /= 10;
        }

        long long divisor = digitSum + digitProduct;
        return original % divisor == 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna