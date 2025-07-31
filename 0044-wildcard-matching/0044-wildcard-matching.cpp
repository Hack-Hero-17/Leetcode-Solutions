 class Solution {
 public:

     bool func(int ind1,int ind2,string &s1,string &s2,vector<vector<int>>&dp){

         if(ind1<0 && ind2<0) return true;
         if(ind1<0 && ind2>=0) return false;
         if(ind2<0 && ind1>=0){
             for(int i=ind1;i>=0;i--){
                 if(s1[i]!='*') return false;
             }
             return true;
         }
         if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
         if(s1[ind1]==s2[ind2] || s1[ind1]=='?') return dp[ind1][ind2]=func(ind1-1,ind2-1,s1,s2,dp);
         if(s1[ind1]=='*') return dp[ind1][ind2]=func(ind1-1,ind2,s1,s2,dp) || func(ind1,ind2-1,s1,s2,dp);
         return dp[ind1][ind2]=false;
     }

     bool isMatch(string s, string p) {
         int n=s.size();
         int m=p.size();
         vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
         return func(m-1,n-1,p,s,dp);
     }
 };