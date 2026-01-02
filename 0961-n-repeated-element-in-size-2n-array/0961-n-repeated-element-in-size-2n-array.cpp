class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        bitset<10001> seen=0;
        for(int x: nums){
            if (seen[x]) return x;
            seen[x]=1;
        }
        return -1;
    }
};