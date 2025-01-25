class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> parent(n), rank(n);

        // Union-Find initialization
        iota(parent.begin(), parent.end(), 0);
        fill(rank.begin(), rank.end(), 0);

        // Find function with path compression
        function<int(int)> find = [&](int x) {
            if (x != parent[x]) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        // Union function with union by rank
        auto unionSet = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
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

        // Build groups of indices that can swap
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (abs(nums[i] - nums[j]) <= limit) {
                    unionSet(i, j);
                }
            }
        }

        // Group indices based on their roots
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; ++i) {
            groups[find(i)].push_back(i);
        }

        // Sort values within each group
        vector<int> result = nums;
        for (auto& [root, indices] : groups) {
            vector<int> values;
            for (int idx : indices) {
                values.push_back(nums[idx]);
            }
            sort(values.begin(), values.end());
            sort(indices.begin(), indices.end());
            for (int k = 0; k < indices.size(); ++k) {
                result[indices[k]] = values[k];
            }
        }

        return result;
    }
};