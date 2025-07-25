class Solution {
public:
    int calculate(string s) {
        stack<pair<int,int>> st;
        long long int sum = 0;
        int sign = +1;
        for( int i=0 ; i<s.length() ; i++ ){
            char ch = s[i];
            if( isdigit(ch) ){
                long long int num = 0;
                while( i<s.length() && isdigit(s[i]) ){
                    num = num*10 + s[i] - '0';
                    i++;
                }
                i--;
                sum += (num*sign);
                sign = +1;
            }
            else if( ch == '(' ){
                st.push( {sum,sign} );
                sum = 0;
                sign = +1;
            }
            else if( ch == ')' ){
                sum = st.top().first + ( st.top().second * sum );
                st.pop();
            }
            else if( ch == '-')
           {
               // toggle sign
               sign = (-1 * sign);
           }
        }
        return sum;
    }
};