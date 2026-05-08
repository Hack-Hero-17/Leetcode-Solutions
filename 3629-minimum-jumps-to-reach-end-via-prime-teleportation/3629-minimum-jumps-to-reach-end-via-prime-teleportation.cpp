// 3rd version
constexpr int M=1e6+1, N=1e5+1;
bitset<M> sieve;
int pIdx[M]={[0 ... (M-1)]=-1};
int primes[80000];
int sz=0;
static void Sieve(){
    if (sieve[0]) return;
    sieve[0]=sieve[1]=1;
    for(int i=2; i<=1000; i+=1+(i>2)){
        if(sieve[i]) continue;
        primes[sz]=i;
        pIdx[i]=sz++;
        for(int j=i*i; j<M; j+=i)
            sieve[j]=1;
    }
    for(int i=1001; i<M; i+=2){
        if(!sieve[i]){
            primes[sz]=i;
            pIdx[i]=sz++;
        }
    }
}
int mp[80000]={[0 ... 79999]=-1};// as heads of linked lists
int nxt[N]={[0 ... N-1]=-1};
int q[N], front, back;
class Solution {
public:
    static void reset(int n, int maxPidx){
        memset(nxt, -1, sizeof(int)*n);
        memset(mp, -1, sizeof(int)*(maxPidx+1)); 
    }
    static int minJumps(vector<int>& nums) {
        Sieve();
    //    cout<<sz<<endl;
        const int n=nums.size();

        int maxPidx=-1;
        for(int i=0; i<n; i++){
            const int x=nums[i];
            if(!sieve[x]){
                int idx=pIdx[x];
                nxt[i]=mp[idx];
                mp[idx]=i;
                maxPidx=max(maxPidx, idx);
            }
        }
        bitset<N> vis;
        front=back=0;
        q[back++]=n-1;
        vis[n-1]=1;
        for(int d=0; front<back; d++){
            int qz=back-front;
            while(qz--){
                auto i=q[front++];
                if(i==0){
                    reset(n, maxPidx);
                    return d;
                }
                int x=nums[i];
                if(i>0 && !vis[i-1]){
                    vis[i-1]=1; 
                    q[back++]=i-1;
                }
                if(i<n-1 && !vis[i+1]){
                    vis[i+1]=1;
                    q[back++]=i+1;
                }
                
                for(int j=0; j<sz && x>1; j++){
                    int p=primes[j];
                    if (!sieve[x]) p=x;
                    if(x%p==0){
                        const int idx=pIdx[p];
                        while(x%p==0) x/=p;
                        for(int j=mp[idx]; j!=-1; j=nxt[j]){
                            if(!vis[j]){ vis[j]=1; q[back++]=j; }
                        }
                        mp[idx]=-1;
                    }
                }
            }
        }
        return -1;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();