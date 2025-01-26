class Solution {
public:
    string reverseWords(string s) {
       auto trim = [](string& str) {
            int start = 0, end = str.size() - 1;
            while (start <= end && str[start] == ' ') ++start;
            while (end >= start && str[end] == ' ') --end;
            str = str.substr(start, end - start + 1);
        };

        trim(s);

        // Split the words
        vector<string> words;
        stringstream ss(s);
        string word;

        while (ss >> word) {
            words.push_back(word);
        }

        // Reverse the words
        reverse(words.begin(), words.end());

        // Join the words
        string result;
        for (int i = 0; i < words.size(); ++i) {
            result += words[i];
            if (i < words.size() - 1) {
                result += " ";
            }
        }

        return result;
    }
};