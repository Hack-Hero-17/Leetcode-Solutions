class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        vector<int> indx;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push(s[i]);
                indx.push_back(i);
            }
            else if(s[i] == ')') {
                if(!st.empty()) {
                    st.pop();
                    indx.pop_back();
                }
                else {
                    indx.push_back(i);
                }
            }
        }

        // Remove indices in reverse order so that indx not shift
        sort(indx.rbegin(), indx.rend());
        for(int i = 0; i < indx.size(); i++) {
            s.erase(s.begin() + indx[i]);
        }

        return s;
    }
};