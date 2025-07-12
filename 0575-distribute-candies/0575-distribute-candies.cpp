class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int half=candyType.size()/2;
        
        unordered_set<int>st;

        for(int &i:candyType){
            if(st.size()==half) return st.size();
            st.insert(i);
        }
        return st.size();
    }
};