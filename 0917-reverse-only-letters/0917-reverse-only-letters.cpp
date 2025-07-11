class Solution {
public:
    string reverseOnlyLetters(string s) {
        vector<char> let;
        vector<int> pos;

         for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a' && s[i]<='z' || s[i]>='A'&&s[i]<='Z')
            {
                let.push_back(s[i]);
                pos.push_back(i);
            }
        }
        reverse(let.begin(),let.end());
        for(int i=0;i<pos.size();i++)
        {
            s[pos[i]]=let[i];
        }
        return s;
    }
};