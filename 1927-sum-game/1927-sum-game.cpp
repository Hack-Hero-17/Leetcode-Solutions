class Solution {
public:
    bool sumGame(string& num) {
        const int n=num.size(), n2=n>>1;
        int diff=0;
        for(int i=0; i<n; i++){
            const char c=num[i];
            bool isq=c=='?', half=i<n2;
            int sgn=(half<<1)-1;
            int d=(-isq & 9)+(-!isq & (c-'0')<<1);
            diff+=sgn*d;
        }
        return diff!=0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna