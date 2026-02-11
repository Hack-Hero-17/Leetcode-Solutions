class Solution {
public:

    struct segment_tree {
        int n;
        vector<int> mn, mx, lazy;

        segment_tree(int n) : n(n) {
            mn.assign(4*n, 0);
            mx.assign(4*n, 0);
            lazy.assign(4*n, 0);
        }

        void push(int v) {
            if(lazy[v] != 0) {
                for(int u : {v*2, v*2+1}) {
                    mn[u] += lazy[v];
                    mx[u] += lazy[v];
                    lazy[u] += lazy[v];
                }
                lazy[v] = 0;
            }
        }

        void update(int v, int tl, int tr, int l, int r, int add) {
            if(l > r) return;
            if(l <= tl && tr <= r) {
                mn[v] += add;
                mx[v] += add;
                lazy[v] += add;
                return;
            }
            push(v);
            int tm = (tl + tr) / 2;
            update(v*2, tl, tm, l, min(r, tm), add);
            update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
            mn[v] = min(mn[v*2], mn[v*2+1]);
            mx[v] = max(mx[v*2], mx[v*2+1]);
        }

        void updaterange(int l, int r, int val) {
            update(1, 0, n-1, l, r, val);
        }

        int queryfirstzero(int v, int tl, int tr, int l, int r) {
            if(l > r || mn[v] > 0 || mx[v] < 0) return -1;
            if(tl == tr) return tl;

            push(v);
            int tm = (tl + tr) / 2;

            int res = queryfirstzero(v*2, tl, tm, l, min(r, tm));
            if(res == -1)
                res = queryfirstzero(v*2+1, tm+1, tr, max(l, tm+1), r);
            return res;
        }

        int queryfirstzero(int l, int r) {
            return queryfirstzero(1, 0, n-1, l, r);
        }
    };

    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        segment_tree s(n);
        int res = 0;

        unordered_map<int,int> m;
        for(int i =0 ;i <n ; i++ ){

            int l = m.count(nums[i]) ? m[nums[i]] + 1 : 0;

            if(nums[i]%2==0){
                s.updaterange(l,i,1);
            }
            else{
                s.updaterange(l,i,-1);
            }

            int in = s.queryfirstzero(0,i);
            if(in!=-1){
                res =max(res,i-in+1);
            }
            m[nums[i]] = i;
        }
        return res;
    }
};