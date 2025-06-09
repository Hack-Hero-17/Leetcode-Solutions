class Solution {
public:
    void solve(vector<int>& vec, int idx, int n) {
        if(idx == n) {
            return;
        }    

        int size = vec.size();

        for(int i=size-1; i>=0; i--) {
            vec.push_back(((1 << idx) | vec[i]));
        }

        solve(vec, idx+1, n);
    }
    vector<int> grayCode(int n) {
        vector<int> vec = {0, 1};
        solve(vec, 1, n);
        return vec;
    }
};