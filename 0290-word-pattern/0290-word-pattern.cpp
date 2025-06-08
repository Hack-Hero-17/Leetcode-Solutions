class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;   // Maps pattern character to word
        unordered_map<string, char> wordToChar;   // Maps word to pattern character

        istringstream stream(s);
        string word;
        int i = 0;

        // Read each word from input string 's'
        while (stream >> word) {
            if (i >= pattern.size()) return false; // More words than pattern characters

            char currentChar = pattern[i];

            // If currentChar already mapped to some word, check consistency
            if (charToWord.count(currentChar)) {
                if (charToWord[currentChar] != word)
                    return false; // Mapping mismatch
            } else {
                charToWord[currentChar] = word; // Create new mapping
            }

            // If word already mapped to some character, check consistency
            if (wordToChar.count(word)) {
                if (wordToChar[word] != currentChar)
                    return false; // Mapping mismatch
            } else {
                wordToChar[word] = currentChar; // Create new mapping
            }

            i++;
        }

        // Ensure pattern isn't longer than the number of words
        return i == pattern.size();
    }
};