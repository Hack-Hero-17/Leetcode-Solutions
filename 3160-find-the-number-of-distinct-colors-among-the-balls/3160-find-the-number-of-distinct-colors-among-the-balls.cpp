class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor; // Maps ball label to its current color
    unordered_map<int, int> colorCount; // Maps color to its frequency
    unordered_set<int> distinctColors; // Stores distinct colors
    vector<int> result; // Stores results after each query

    for (const auto& query : queries) {
        int ball = query[0];
        int color = query[1];

        // If ball already has a color, decrease count of old color
        if (ballColor.count(ball)) {
            int oldColor = ballColor[ball];
            if (--colorCount[oldColor] == 0) {
                distinctColors.erase(oldColor); // Remove old color if count becomes 0
            }
        }

        // Assign new color and update count
        ballColor[ball] = color;
        if (++colorCount[color] == 1) {
            distinctColors.insert(color); // Add new color if it's first occurrence
        }

        // Store the count of distinct colors
        result.push_back(distinctColors.size());
    }

    return result;
    }
};