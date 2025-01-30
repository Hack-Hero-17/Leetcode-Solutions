class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n + 1, 0); // 0: unvisited, 1: color1, -1: color2
        vector<int> visited(n + 1, 0);

        function<bool(int)> isBipartite = [&](int node) {
            queue<int> q;
            q.push(node);
            color[node] = 1;
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                
                for (int neighbor : graph[curr]) {
                    if (color[neighbor] == 0) {
                        color[neighbor] = -color[curr];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[curr]) {
                        return false; // Found an odd cycle
                    }
                }
            }
            return true;
        };

        function<int(int)> maxBFSDepth = [&](int start) {
            queue<int> q;
            q.push(start);
            unordered_map<int, int> depth;
            depth[start] = 1;
            int maxDepth = 1;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int neighbor : graph[node]) {
                    if (!depth.count(neighbor)) {
                        depth[neighbor] = depth[node] + 1;
                        maxDepth = max(maxDepth, depth[neighbor]);
                        q.push(neighbor);
                    }
                }
            }
            return maxDepth;
        };

        int maxGroups = 0;
        
        for (int i = 1; i <= n; i++) {
            if (color[i] == 0) {
                if (!isBipartite(i)) return -1; // Not bipartite, return -1

                // BFS from all nodes in the component to get max depth
                int componentMax = 0;
                vector<int> componentNodes;
                queue<int> q;
                q.push(i);
                visited[i] = 1;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    componentNodes.push_back(node);

                    for (int neighbor : graph[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = 1;
                            q.push(neighbor);
                        }
                    }
                }

                // Get the max BFS depth from any node in the component
                for (int node : componentNodes) {
                    componentMax = max(componentMax, maxBFSDepth(node));
                }
                maxGroups += componentMax;
            }
        }
        return maxGroups;
    }
};