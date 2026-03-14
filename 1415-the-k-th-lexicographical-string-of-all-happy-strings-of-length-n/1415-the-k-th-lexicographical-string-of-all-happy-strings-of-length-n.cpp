class Solution {
public:
    string ans = "";
    int count = 0;

    void backtrack(string& curr, int n, int k) {
        if (!ans.empty()) return;

        if (curr.size() == n) {
            count++;
            if (count == k) ans = curr;
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (!curr.empty() && curr.back() == ch) continue;

            curr.push_back(ch);
            backtrack(curr, n, k);
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        backtrack(curr, n, k);
        return ans;
    }
};