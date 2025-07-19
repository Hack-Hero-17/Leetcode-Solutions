class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);

        for(auto &edge:prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> Indegree(n);
        for(int i{0};i<n;i++){
            for(auto &it:adj[i]){
                Indegree[it]++;
            }
        }
        
        queue<int> q;
        
        for(int i{0};i<n;i++){
            if(Indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> res;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            
            for(auto &it:adj[node]){
                Indegree[it]--;
                
                if(Indegree[it]==0){
                    q.push(it);
                }
            }
        }
        vector<int> empty;
        return (res.size()==n)?res:empty;
    }
};