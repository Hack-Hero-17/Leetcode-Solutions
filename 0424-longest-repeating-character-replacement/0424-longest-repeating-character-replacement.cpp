#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freqs;
        int res = 0, i = 0, maxFreq = 0;

        for (int j = 0; j < s.size(); j++) {
            freqs[s[j]]++;
            maxFreq = max(maxFreq, freqs[s[j]]);

            while ((j - i + 1) - maxFreq > k) {
                freqs[s[i]]--;
                i++;
            }

            res = max(res, j - i + 1);
        }

        return res;
    }
};