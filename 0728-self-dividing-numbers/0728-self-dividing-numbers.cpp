int checkDivisible(int num) {
    int temp = num;
    int isDiv = 0, count = 0;
    while (temp > 0) {
        int digit = temp % 10;
        if (digit == 0) return 0; // A digit is zero, cannot be self-dividing
        if (num % digit == 0) isDiv++; // Check if num is divisible by the digit
        count++;
        temp /= 10; // Remove the last digit
    }
    if (count == isDiv) return num; // All digits divide the number
    return 0; // Not a self-dividing number
}

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> vec;
        int store;
        for (int i = left; i <= right; i++) {
            store = checkDivisible(i);
            if (store == i) vec.push_back(i); // If it's self-dividing, add to the result
        }
        return vec;
    }
};