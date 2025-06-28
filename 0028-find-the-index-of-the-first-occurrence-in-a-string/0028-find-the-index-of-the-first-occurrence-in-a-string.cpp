class Solution {
public:
    int strStr(string haystack, string needle) {
        if( needle.length() > haystack.length() ) return -1;
        int len = needle.length();
        for( int i=0; i<=haystack.length()-len; i++ ){
            if( needle == haystack.substr(i,len) )
                return i;
        }
        return -1;
    }
};