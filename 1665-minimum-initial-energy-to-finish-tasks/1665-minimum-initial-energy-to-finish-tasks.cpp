constexpr int M=1e4;
int Sum[M]={0}; // d=min-act -> sum of all act with same d
class Solution {
public:
    static int minimumEffort(vector<vector<int>>& tasks) {
        const int n=tasks.size();
        int dMin=M, dMax=0;
        for(const auto& t: tasks){
            const int a=t[0], d=t[1]-a;
            Sum[d]+=a;
            dMin=min(dMin, d);
            dMax=max(dMax, d);
        }
        int energy=0;
        for(int d=dMin; d<=dMax; d++){
            if (Sum[d]==0) continue;
            energy=max(energy+Sum[d], Sum[d]+d);
        }
        // reset for the next testcase
        memset(Sum+dMin, 0, (dMax+1-dMin)*sizeof(int));
        return energy;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna