class Solution {
public:
    bool helper(string curStr, int curI, int n,  unordered_map<string, vector<char>>& triPatterns) {
        if (n == 1) return true;
        bool res = false;
        if (curI < n - 1) {
            string curBot = curStr.substr(curI, 2);
            for (int i = 0; i < triPatterns[curBot].size(); ++i) {
                curStr[curI] = triPatterns[curBot][i];
                res |= helper(curStr, curI + 1, n, triPatterns);
                if (res) return true;
            }
        } else {
            res |= helper(curStr, 0, n - 1, triPatterns);
            if (res) return true;
        }

        return res;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> triPatterns;
        for (int i = 0; i < allowed.size(); ++i) {
            triPatterns[allowed[i].substr(0, 2)].push_back(allowed[i][2]);
        }

        return helper(bottom, 0, bottom.size(), triPatterns);
    }
};