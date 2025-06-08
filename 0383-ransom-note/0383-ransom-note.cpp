class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mg;

        for( int i=0 ; i<magazine.length() ; i++ ){
            mg[magazine[i]]++;
        }

        for( int i=0 ; i<ransomNote.length() ; i++ ){
            if( --mg[ransomNote[i]]<0)
                return false;
        }
        return true;
    }
};