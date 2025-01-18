class Solution {
public:
    bool isHappy(int n) {
        int temp = n;
    while (temp != 1 && temp != 4) {
        int digitSum = 0;
        while (temp > 0) {
            int digit = temp % 10;
            digitSum += digit * digit;
            temp /= 10;
        }
        temp = digitSum;
    }
    return temp == 1;
    }
};