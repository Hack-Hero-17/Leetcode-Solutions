class Solution {
public:
    string convert_To_Base_N(unsigned int num, int base) {
        if (num == 0) {
            return "0";
        }

        const string digits = "0123456789abcdef";
        string ans;

        while (num > 0) {
            ans += digits[num % base];
            num /= base;
        }
        reverse(begin(ans), end(ans));

        return ans;
    }

    string toHex(int num) {
        unsigned int unsigned_Num = static_cast<unsigned int>(num);
        return convert_To_Base_N(unsigned_Num, 16);
    }
};