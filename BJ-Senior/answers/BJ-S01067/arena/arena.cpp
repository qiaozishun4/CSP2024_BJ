#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=101000;
int T,n,m,nengli[maxn],xw[maxn],dp[maxn],mx[maxn],a[4],ans,L;
vector<int>chouqian[20];char c;
void dfs(int now,int x,int y){
    if(now>=(1<<y)){
        mx[now]=nengli[now-(1<<y)+1],dp[now]=now-(1<<y)+1;
        return;
    }int cc=(int)log2(now);
    dfs(now<<1,x,y),dfs(now<<1^1,x,y);
    mx[now]=max(mx[now<<1],mx[now<<1^1]);
    if(chouqian[y-cc][now-(1<<cc)]==0&&(now-(1<<cc)+1)*(1<<y-cc)-(1<<y-cc-1)<=x)dp[now]=(mx[now<<1]>=y-cc)?dp[now<<1]:dp[now<<1^1];
    else if(chouqian[y-cc][now-(1<<cc)]==0)dp[now]=dp[now<<1]+dp[now<<1^1];
    else if((now-(1<<cc)+1)*(1<<y-cc)<=x)dp[now]=(mx[now<<1^1]>=y-cc)?dp[now<<1^1]:dp[now<<1];
    else dp[now]=dp[now<<1]+dp[now<<1^1];
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    memset(nengli,-1,sizeof(nengli));
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>nengli[i];
    for(int i=1;i<=m;i++)cin>>xw[i];
    L=ceil(log2(n));
    for(int i=1;i<=L;i++)for(int j=1;j<=1<<(L-i);j++){
        cin>>c;chouqian[i].push_back(c-48);
    }
    cin>>T;
    while(T--){
        cin>>a[0]>>a[1]>>a[2]>>a[3];ans=0;
        for(int i=1;i<=n;i++)nengli[i]^=a[i&3];
        for(int i=1;i<=m;i++){
            dfs(1,xw[i],ceil(log2(xw[i])));
            ans^=i*dp[1];
        }
        cout<<ans<<"\n";
        for(int i=1;i<=n;i++)nengli[i]^=a[i&3];
    }
}