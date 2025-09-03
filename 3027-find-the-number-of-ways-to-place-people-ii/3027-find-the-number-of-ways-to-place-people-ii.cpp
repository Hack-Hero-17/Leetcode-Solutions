class Solution {
public:
static bool comp(vector<int>& a,vector<int>& b)
{
    if(a[0]==b[0])
    return a[1]>b[1];
    return a[0]<b[0];
}
    int numberOfPairs(vector<vector<int>>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end(),comp);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int top=arr[i][1];
            int bot=INT_MIN;
            for(int j=i+1;j<n;j++)
            {
                int y=arr[j][1];
                if(bot<y&&y<=top)
                {
                    cnt++;
                    bot=y;
                    if(bot==top)
                    break;
                }
            }
        }
        return cnt;
    }
};