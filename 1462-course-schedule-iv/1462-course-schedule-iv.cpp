class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> isPrerequisite(n, vector<bool>(n, false));
    
        // Fill the matrix with direct prerequisites
        for (const auto& pre : prerequisites) {
            isPrerequisite[pre[0]][pre[1]] = true;
        }
        
        // Floyd-Warshall Algorithm for transitive closure
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (isPrerequisite[i][k] && isPrerequisite[k][j]) {
                        isPrerequisite[i][j] = true;
                    }
                }
            }
        }
        
        // Answer each query
        vector<bool> results;
        for (const auto& query : queries) {
            results.push_back(isPrerequisite[query[0]][query[1]]);
        }
        
        return results;
    }
};