class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for( char ch : s )
        {
            if( isdigit(ch) )
            {     st.pop();
                  continue;
            }
            st.push(ch);
        }
        string str="";
        while(!st.empty())
        {
            str += st.top();
            st.pop();
        }
        reverse( str.begin() , str.end() );
        return str;
    }
};