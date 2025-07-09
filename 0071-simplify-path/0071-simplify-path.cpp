#include<iostream>
class Solution {
    private :
        vector<string> st;
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string comp;
        while( getline( ss, comp , '/' ) ){
            if( comp == "" || comp =="."  ){
                continue;
            }
            if( comp == ".." ){
                if( !st.empty() ){
                    st.pop_back();
                }
            }
            else{
                st.push_back(comp);
            }
        }

        stringstream simplifiedPath;
        for( auto & s : st ){
            simplifiedPath << "/" << s;
        }

        return simplifiedPath.str().empty() ? "/" : simplifiedPath.str();
    }
};