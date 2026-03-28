class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        vector<char> word(n, 0);
        char current = 'a';

        // construct the string
        for (int i = 0; i < n; i++) {
            if (word[i] == 0) {
                if (current > 'z') return "";
                word[i] = current;
                for (int j = i + 1; j < n; j++) {
                    if (lcp[i][j] > 0) {
                        word[j] = word[i];
                    }
                }
                current++;
            }
        }

        // verify LCP matrix
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] != word[j]) {
                    if (lcp[i][j] != 0) return "";
                } else {
                    if (i == n - 1 || j == n - 1) {
                        if (lcp[i][j] != 1) return "";
                    } else {
                        if (lcp[i][j] != lcp[i + 1][j + 1] + 1) return "";
                    }
                }
            }
        }

        return string(word.begin(), word.end());
    }
};