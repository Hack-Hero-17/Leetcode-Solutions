class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> parent(n), rank(n);
        
        // Initialize Union-Find
        iota(parent.begin(), parent.end(), 0);  // parent[i] = i
        
        function<int(int)> find = [&](int x) {
            if (x != parent[x]) parent[x] = find(parent[x]);
            return parent[x];
        };
        
        auto unionSet = [&](int x, int y) {
            int rootX = find(x), rootY = find(y);
            if (rootX != rootY) {
                if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        };
        
        // Union all pairs
        for (auto& p : pairs) {
            unionSet(p[0], p[1]);
        }
        
        // Group indices by their connected component
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; ++i) {
            groups[find(i)].push_back(i);
        }
        
        // Sort characters within each component
        string result = s;
        for (auto& [_, indices] : groups) {
            string chars;
            for (int idx : indices) {
                chars += s[idx];
            }
            sort(chars.begin(), chars.end());
            sort(indices.begin(), indices.end());
            for (int i = 0; i < indices.size(); ++i) {
                result[indices[i]] = chars[i];
            }
        }
        
        return result;
    }
};