class Solution {
public:
    int numberOfSubstrings(string s) {
       vector<int> count(3, 0);  // Count array for 'a', 'b', 'c'
    int left = 0, right = 0, n = s.size(), result = 0;

    for (right = 0; right < n; right++) {
        count[s[right] - 'a']++;  // Increase frequency of current character

        // Shrink the window when all three characters are present
        while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
            result += (n - right); // Every substring starting from 'left' to 'n' is valid
            count[s[left] - 'a']--; // Reduce the count of leftmost character
            left++;  // Move left pointer
        }
    }

    return result; 
    }
};