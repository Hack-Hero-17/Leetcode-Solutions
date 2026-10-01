class Solution {
public:
    bool isValid(string s) {
    stack<char> stk;

    for (char c : s) {
        
        if (c == '(' || c == '{' || c == '[') {
            stk.push(c);
        } else {
            if (stk.empty() || 
                (c == ')' && stk.top() != '(') || 
                (c == '}' && stk.top() != '{') || 
                (c == ']' && stk.top() != '[')) {
                return false;
            }
            stk.pop();
        }
    }
    
    return stk.empty();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna