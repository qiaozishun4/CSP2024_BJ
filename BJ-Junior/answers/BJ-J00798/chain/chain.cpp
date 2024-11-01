#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 105
int t,n,k,q;
int l[5][MAXN];
vector<int> a[5][MAXN];
bool dp[MAXM][MAXN];
int f[MAXM][MAXN];
int r[5][MAXN],c[5][MAXN];
bool vis[MAXM][MAXN];
void dp_(int mx){
    memset(dp,0,sizeof(dp));
    memset(f,0,sizeof(f));
    memset(vis,0,sizeof(vis));
    dp[0][1]=1;
    for(int p=1;p<=mx;p++){
        for(int i=1;i<=n;i++){
            int sum=0;
            for(int j=0;j<l[t][i];j++){
                if(j>=k and f[p-1][a[t][i][j-k]]!=i)sum-=dp[p-1][a[t][i][j-k]];
                dp[p][a[t][i][j]]=max(dp[p][a[t][i][j]],(bool)(max(0,min(1,sum))));
                if(vis[p][a[t][i][j]]){
                    if(f[p][a[t][i][j]]!=i and (max(0,min(1,sum))))
                        f[p][a[t][i][j]]=0;
                }else{
                    if(max(0,min(1,sum))){
                        f[p][a[t][i][j]]=i;
                        vis[p][a[t][i][j]]=1;
                    }
                }
                if(f[p-1][a[t][i][j]]!=i)sum+=dp[p-1][a[t][i][j]];
                //printf("dp[%d][a[%d][%d]=%d]=%d\n",p,i,j,a[t][i][j],dp[p][a[t][i][j]]);
                //printf("f[%d][a[%d][%d]=%d]=%d\n",p-1,i,j,a[t][i][j],f[p-1][a[t][i][j]]);
            }
        }
    }
    return ;
}
void work(){
    int mx=1;
    for(int i=1;i<=q;i++){
        cin>>r[t][i]>>c[t][i];
        mx=max(mx,r[t][i]);
    }
    dp_(mx);
    for(int i=1;i<=q;i++){
        cout<<dp[r[t][i]][c[t][i]]<<endl;
    }
    return ;
}
void init(){
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[t][i];
            for(int j=1,u;j<=l[t][i];j++){
                cin>>u;
                a[t][i].push_back(u);
            }
        }
        work();
    }
    return ;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    init();
    return 0;
}   