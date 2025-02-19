class Solution {
public:
    void generateHappyStrings(int n, string &current, vector<string> &result) {
        if (current.size() == n) {
            result.push_back(current);
            return;
        }
        
        for (char ch : {'a', 'b', 'c'}) {
            if (current.empty() || current.back() != ch) {
                current.push_back(ch);
                generateHappyStrings(n, current, result);
                current.pop_back();
            }
        }
    }
    
    string getHappyString(int n, int k) {
        vector<string> result;
        string current = "";
        
        generateHappyStrings(n, current, result);
        
        return (k <= result.size()) ? result[k - 1] : "";
    }
};