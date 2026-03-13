class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        auto find = [&](int i) {
            while (i != parent[i]) {
                parent[i] = parent[parent[i]];
                i = parent[i];
            }
            return i;
        };

        int minM = INT_MAX;
        int compCount = n;

        for (const auto& e : edges) {
            if (e[3] == 1) {
                int ru = find(e[0]);
                int rv = find(e[1]);
                if (ru == rv) return -1;
                parent[ru] = rv;
                compCount--;
                if (e[2] < minM) minM = e[2];
            }
        }

        vector<uint64_t> opt;
        opt.reserve(edges.size());

        for (const auto& e : edges) {
            if (e[3] == 0) {
                int ru = find(e[0]);
                int rv = find(e[1]);
                if (ru != rv) {
                    // Packing: weight (30 bits) | ru (17 bits) | rv (17 bits)
                    opt.push_back(((uint64_t)e[2] << 34) | ((uint64_t)ru << 17) | (uint32_t)rv);
                }
            }
        }

        if (compCount == 1) return minM;

        // Radix Sort
        if (opt.size() > 1) {
            vector<uint64_t> temp(opt.size());
            int count[256];
            for (int shift = 34; shift < 64; shift += 8) {
                memset(count, 0, sizeof(count));
                for (size_t i = 0; i < opt.size(); i++) {
                    count[(opt[i] >> shift) & 0xFF]++;
                }
                for (int i = 1; i < 256; i++) {
                    count[i] += count[i - 1];
                }
                for (int i = (int)opt.size() - 1; i >= 0; i--) {
                    temp[--count[(opt[i] >> shift) & 0xFF]] = opt[i];
                }
                opt.swap(temp);
            }
        }

        vector<int> upg;
        upg.reserve(compCount - 1);

        for (int i = (int)opt.size() - 1; i >= 0; i--) {
            uint64_t packed = opt[i];
            int ru = find((packed >> 17) & 0x1FFFF);
            int rv = find(packed & 0x1FFFF);
            
            if (ru != rv) {
                parent[ru] = rv;
                upg.push_back(packed >> 34);
                compCount--;
                if (compCount == 1) break;
            }
        }

        if (compCount > 1) return -1;

        for (int i = (int)upg.size() - 1; i >= 0; i--) {
            if (k > 0) {
                k--;
                int upgraded = upg[i] << 1;
                if (upgraded < minM) minM = upgraded;
            } else {
                if (upg[i] < minM) minM = upg[i];
                break;
            }
        }

        return minM;
    }
};