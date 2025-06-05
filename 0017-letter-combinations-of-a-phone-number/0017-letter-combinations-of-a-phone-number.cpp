class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if( digits.empty() ){
            return res;
        }
        unordered_map<char,string> digitToLetters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        backtrack( 0 , digits , "" , res , digitToLetters );
        return res;
    }

    void backtrack( int ind , string& digits , string comb , vector<string> & res , unordered_map<char,string>& digitToLetters){
        if( ind == digits.size() ){
            res.push_back(comb);
            return;
        }
        string letters = digitToLetters.at(digits[ind]);
        for( char ch : letters ){
            backtrack( ind+1 , digits , comb + (string)ch , res , digitToLetters );
        }
    }
};