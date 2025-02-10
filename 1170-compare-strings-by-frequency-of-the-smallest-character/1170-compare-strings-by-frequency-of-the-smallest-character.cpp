class Solution {
public:
    int getFrequency(const std::string &s) {
        char smallest = 'z';
        int count = 0;
        for (char ch : s) {
            if (ch < smallest) {
                smallest = ch;
                count = 1;
            } else if (ch == smallest) {
                count++;
            }
        }
        return count;
    }

    std::vector<int> numSmallerByFrequency(std::vector<std::string>& queries, std::vector<std::string>& words) {
        std::vector<int> wordFreq;
        
        // Compute frequency for each word
        for (const std::string &word : words) {
            wordFreq.push_back(getFrequency(word));
        }
        
        // Sort the frequency list for binary search
        std::sort(wordFreq.begin(), wordFreq.end());
        
        std::vector<int> result;
        for (const std::string &query : queries) {
            int freq = getFrequency(query);
            
            // Find the first position where wordFreq[i] > freq
            int count = wordFreq.end() - std::upper_bound(wordFreq.begin(), wordFreq.end(), freq);
            result.push_back(count);
        }
        
        return result;
    }
};