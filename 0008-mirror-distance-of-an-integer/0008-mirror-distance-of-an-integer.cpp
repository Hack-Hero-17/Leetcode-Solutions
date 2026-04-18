1class Solution {
2public:
3    int mirrorDistance(int n) {
4        long long rev=0;
5        for(int x=n; x; x/=10){
6            rev=10*rev+x%10;
7        }
8        rev-=n;
9        return rev>=0?rev:-rev;
10    }
11};