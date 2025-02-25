class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
    int maxLength = 0, left = 0;

    for (int right = 0; right < s.length(); right++) {
        if (charIndex.find(s[right]) != charIndex.end()) {
            left = max(left, charIndex[s[right]] + 1);  // Move left to avoid duplicates
        }
        charIndex[s[right]] = right;  // Update last seen index
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
    }
};