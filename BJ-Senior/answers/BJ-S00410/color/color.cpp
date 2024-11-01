#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,a[N],n;
int now[N];
long long dp[N],ans;
vector<long long> ve[N];
void dfs(int dep,long long sc){
    if(dep==n+1){
        ans=max(ans,sc);
        return;
    }
    now[dep]=1;
    for(int i=dep-1;i>=0;i--)
        if(now[i]||i==0){
            if(a[i]==a[dep])
                dfs(dep+1,sc+a[dep]);
            else dfs(dep+1,sc);
            break;
        }
    now[dep]=0;
    for(int i=dep-1;i>=0;i--)
        if(!now[i]||i==0){
            if(a[i]==a[dep])
                dfs(dep+1,sc+a[dep]);
            else dfs(dep+1,sc);
            break;
        }
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        if(n<=15){
            dfs(1,0);
            printf("%lld\n",ans);
            ans=0;
            continue;
        }
        for(int i=1;i<=n;i++) ve[a[i]].push_back(i);
        for(int i=1;i<=n;i++){
            int x=(int)(lower_bound(ve[a[i]].begin(),ve[a[i]].end(),i)-ve[a[i]].begin())-1;
            for(int j=0;j<=x;j++){
                dp[i]=max(dp[i],max(dp[ve[a[i]][j]-1],dp[ve[a[i]][j]+1]));
            }
            if(x>=0) dp[i]+=a[i];
            dp[i]=max(dp[i],dp[i-1]);
        }
        printf("%lld\n",dp[n]);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++) ve[i].clear();
    }
    return 0;
}
