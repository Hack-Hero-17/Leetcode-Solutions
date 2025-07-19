class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st{ bank.begin() , bank.end() };

        if( !st.count(endGene) ) return -1;

        queue<string> Q;
        Q.push(startGene);
        int steps=0, s;
        string cur, t;
        while( ! Q.empty() ){
            s = Q.size();
            while(s--){
                cur = Q.front();
                Q.pop();

                st.erase(cur);
                
                if( cur == endGene )   return steps;

                for( int i=0 ; i<8 ; i++ ){
                    t = cur;
                    t[i] = 'A';
                    if( st.count(t) )  Q.push(t);
                    t[i] = 'C';
                    if( st.count(t) )  Q.push(t);
                    t[i] =  'G';
                    if( st.count(t) )  Q.push(t);
                    t[i] = 'T';
                    if( st.count(t) )  Q.push(t);

                }
            }
            steps++;
        }
        return -1;
    }
};