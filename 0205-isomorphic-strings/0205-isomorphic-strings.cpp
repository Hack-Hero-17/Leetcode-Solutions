class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> S;
        unordered_map<char,int> T;

        for( int i=0 ; i<s.length() ; i++ ){
            if( S.find(s[i]) == S.end() )
                S[s[i]] = i;
            if( T.find(t[i]) == T.end() )
                T[t[i]] = i;
            if( S[s[i]] != T[t[i]] )
                return false;
        }
        return true;
    }
};