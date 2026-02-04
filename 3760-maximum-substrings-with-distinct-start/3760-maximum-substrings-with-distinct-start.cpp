class Solution {
public:
    int maxDistinct(string s) {
        // Hint: Since you want to get the maximum number of substrings starting
        // with distinct characters , the maximum answer will be 26 if all the
        // letters of the English alphabet are present. So just take a frequency
        // vector and count the number of distinct characters present in the
        // vector
        vector<int> freq(26, 0);
        int count = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (freq[s[i] - 'a'] == 0) {
                freq[s[i] - 'a']++;
                count++;
            }
        }
        return count;
    }
};
