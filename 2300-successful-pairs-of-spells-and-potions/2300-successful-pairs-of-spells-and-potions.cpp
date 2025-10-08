class Solution {
public:
    int check(vector<int>&p,int i,long long s,int n1){
        int low = 0;
        int high = n1-1;
        
        if((long long)p[high]*i < s) return n1;
        if((long long)p[low]*i >= s) return 0;

        while(low <=high){
            int mid = low + (high-low)/2;
            if(mid && i*(long long)p[mid] >= s && i*(long long)p[mid-1] <s) return mid;
            else if(i*(long long)p[mid]<s) low = mid +1;
            else high = mid-1;
        }
        return n1;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int n1 = potions.size();
        vector<int>ans;
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++){
            int ind = check(potions,spells[i],success,n1);
            ans.push_back(n1-ind);
        }
        return ans;
    }
};