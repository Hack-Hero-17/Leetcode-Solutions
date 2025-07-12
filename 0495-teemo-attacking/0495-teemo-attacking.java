class Solution {
    public int findPoisonedDuration(int[] tS, int dur) {
        int res=0;
        for(int i=0; i<tS.length-1; i++){
            int n = tS[i+1] - tS[i];
            if(n >= dur){
                res += dur;  // since independent of the next , will remain poisoned for whole duration 
            }
            else{
                res += n;  // if overlapping, will be poisoned only for the diff b/w the current and next time
            }
        }
        return res += dur; // for last time, since it doesn't have a next time to overlap with
    }
}