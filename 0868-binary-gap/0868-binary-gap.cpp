class Solution {
public:
   
    vector<int> decimalToBinary(int n)
    {
        vector<int> binary;
        while (n > 0) 
        {
            binary.push_back(n % 2);
            n /= 2;
        }
        reverse(binary.begin(), binary.end());
        return binary;
    }
    int binaryGap(int n) 
    {
        vector<int> binary = decimalToBinary(n);
        int m = 0;
        int ind = -1;

        for (int i = 0; i < binary.size(); ++i) {
            if (binary[i] == 1) {
                if (ind != -1) {
                    m = max(m, i - ind);
                }
                ind = i;
            }
        }

        return m;
    }
};