class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for( auto &p : prerequisites ){
            int course = p[0];
            int prerequisite = p[1];
            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        vector<int> order;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            order.push_back(course);
            for( auto &p : adj[course] ){
                indegree[p]--;
                if( indegree[p] == 0 )
                    q.push(p);
            }
        }

        if( order.size() == numCourses )
            return true;
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna