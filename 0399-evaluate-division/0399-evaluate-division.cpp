class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map< string, unordered_map<string,double> > graph;
        unordered_map< string, unordered_map<string,double> > memo;

        for( int i=0 ; i<equations.size() ; i++ ){
            string a = equations[i][0];
            string b = equations[i][1];
            graph[a][b] = values[i];
            graph[b][a] = 1/values[i];
        }

        vector<double> results;

        for( auto & query : queries ){
            unordered_set<string> visited;
            double result = dfs( query[0] , query[1] , graph , memo , visited );
            results.push_back(result);
        }
        
        return results;
    }
    double dfs( string num , string den , unordered_map< string, unordered_map<string,double> > graph, unordered_map< string, unordered_map<string,double> > memo , unordered_set<string> & visited ){
        if( graph.find(num) == graph.end() || graph.find(den) == graph.end() )
            return -1.0;
        if( graph[num].find(den) != graph[num].end() )
            return graph[num][den];
        if( memo[num].find(den) != memo[num].end() )
            return memo[num][den];
        
        visited.insert(num);

        for( auto & neighbour : graph[num] ){
            if( visited.find(neighbour.first) == visited.end() ){
                double subResult = dfs( neighbour.first, den , graph , memo , visited );
                if( subResult !=  -1.0 ){
                     double fullResult = neighbour.second * subResult;
                    memo[num][den] = fullResult;
                    memo[den][num] = 1.0 / fullResult;
                    return fullResult;
                }
            }
        }

        return -1.0;
    }
};