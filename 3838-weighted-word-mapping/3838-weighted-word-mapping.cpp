class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        const int n=words.size();
        string ans(n, ' ');
        int i=0;
        for(const string& w: words){
            int Sum=accumulate(w.begin(), w.end(), 0, 
            [&](int sum, char c){
                return sum+=weights[c-'a'];
            });
            ans[i++]='a'+(25-Sum%26);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna