class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {
        int n = words.size();
        vector<int> next(n, n), dp(n, 1);
        unordered_map<long long, vector<int>> maskMap;
        int bestStart = 0;

        for (int i = n - 1; i >= 0; --i) {
            const string& word = words[i];
            int len = word.length();
            long long fullMask = 0;
            vector<long long> charMasks(len);

            // Encode word into bitmask
            for (int j = 0; j < len; ++j) {
                long long shift = (long long)(word[j] - 'a' + 1) << (5 * j);
                charMasks[j] = shift;
                fullMask |= shift;
            }

            int maxLen = 1;
            int nextIndex = n;

            // Try all Hamming-1 mutations
            for (int j = 0; j < len; ++j) {
                long long alteredMask = fullMask ^ charMasks[j];
                if (maskMap.count(alteredMask)) {
                    for (int idx : maskMap[alteredMask]) {
                        if (groups[i] != groups[idx] && dp[idx] + 1 > maxLen) {
                            maxLen = dp[idx] + 1;
                            nextIndex = idx;
                        }
                    }
                }
            }

            dp[i] = maxLen;
            next[i] = nextIndex;
            if (dp[i] > dp[bestStart])
                bestStart = i;

            // Insert this word's altered masks into map
            for (int j = 0; j < len; ++j) {
                long long alteredMask = fullMask ^ charMasks[j];
                maskMap[alteredMask].push_back(i);
            }
        }

        vector<string> result;
        for (int i = bestStart; i < n; i = next[i]) {
            result.push_back(words[i]);
        }

        return result;
    }
};