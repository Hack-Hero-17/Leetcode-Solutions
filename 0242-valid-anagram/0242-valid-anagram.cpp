class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.length() != t.length() ) return false;
    
        unordered_map<char, int> charT;
        for( int i=0 ; i<s.length() ; i++ ){
            charT[t[i]]++;
        }

        for( int i=0; i<s.length() ; i++ ){
            if( charT[s[i]] == 0)
                return false;
            charT[s[i]]--;
        }
        return true;
    }
};