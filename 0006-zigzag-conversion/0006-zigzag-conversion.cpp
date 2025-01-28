class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s; // If only one row, return the string as-is

        vector<string> rows(min(numRows, int(s.size())));
        int currentRow = 0;
        bool goingDown = false;

        // Traverse the string and distribute characters across rows
        for (char c : s) {
            rows[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown; // Change direction at top or bottom
            }
            currentRow += goingDown ? 1 : -1;
        }

        // Combine all rows into a single string
        string result;
        for (string row : rows) {
            result += row;
        }

        return result;
    }
};