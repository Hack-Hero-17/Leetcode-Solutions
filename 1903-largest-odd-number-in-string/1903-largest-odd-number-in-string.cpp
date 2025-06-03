class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        if( num.back()%2 == 1 ) return num;
        int i = n-1;
        while( i>=0 ){
            int nu = num[i];
            if( nu%2 == 1 ) return num.substr(0,i+1);
            i--;
        }
        return "";
    }
};