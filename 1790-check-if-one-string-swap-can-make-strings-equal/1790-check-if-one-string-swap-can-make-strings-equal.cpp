class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;  // Already equal

    vector<int> diff;
    
    // Find indices where s1 and s2 differ
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            diff.push_back(i);
        }
    }

    // There must be exactly two differences and swapping must make them equal
    return (diff.size() == 2 && 
            s1[diff[0]] == s2[diff[1]] && 
            s1[diff[1]] == s2[diff[0]]);
    }
};