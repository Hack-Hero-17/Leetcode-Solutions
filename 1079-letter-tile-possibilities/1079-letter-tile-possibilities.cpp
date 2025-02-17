class Solution {
public:
    void backtrack(unordered_map<char, int>& freq, int& count) {
    for (auto& [ch, f] : freq) {
        if (f > 0) {  // If the letter is available
            f--;       // Use it
            count++;   // Count this sequence
            backtrack(freq, count); // Recur
            f++;       // Backtrack to restore count
        }
    }
}

int numTilePossibilities(string tiles) {
    unordered_map<char, int> freq;
    for (char ch : tiles) {
        freq[ch]++;  // Count occurrences
    }
    
    int count = 0;
    backtrack(freq, count);
    return count;
}
};