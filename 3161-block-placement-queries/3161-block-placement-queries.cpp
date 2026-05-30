class SegTree {
    int n;
    vector<int> tree;
public:
    SegTree(int size) {
        n = 1;
        while (n <= size) n *= 2;
        tree.assign(2 * n, 0);
    }
    
    void update(int i, int val) {
        for (tree[i += n] = val; i > 1; i >>= 1)
            tree[i >> 1] = max(tree[i], tree[i ^ 1]);
    }
    
    int query(int r) {
        int res = 0;

        for (int l = n, r_idx = r + n + 1; l < r_idx; l >>= 1, r_idx >>= 1) {
            if (l & 1) 
                res = max(res, tree[l++]);
            if (r_idx & 1) 
                res = max(res, tree[--r_idx]);
        }
        return res;
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_x = 0;
        for (const auto& q : queries) 
            max_x = max(max_x, q[1]);
        
        SegTree st(max_x + 1);
        set<int> obstacles = {0}; 
        vector<bool> res;
        
        for (const auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                auto it = obstacles.lower_bound(x);
                int nxt = (it != obstacles.end()) ? *it : -1;
                int prev = *(--it); 
                st.update(x, x - prev);
                
                if (nxt != -1) {
                    st.update(nxt, nxt - x);
                }
                obstacles.insert(x);
            } else {
                int x = q[1];
                int sz = q[2];
            
                auto it = obstacles.upper_bound(x);
                int prev = *(--it);

                int mx = max(x - prev, st.query(prev));
                res.push_back(sz <= mx);
            }
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna