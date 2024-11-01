
#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
long long maxn,dp[2005][2005],sum[200005],dp2[200005];
bool f[20];
void dfs(int w){
    if(w==n+1){
        int lastt[2]={0,0};
        long long cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==lastt[f[i]]) cnt+=a[i];
            lastt[f[i]]=a[i];
        }
        maxn=max(maxn,cnt);
        return;
    }
    f[w]=0;
    dfs(w+1);
    f[w]=1;
    dfs(w+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        if(n<=15){
            maxn=0;
            dfs(1);
            printf("%lld\n",maxn);
        }else{
             memset(dp,0,sizeof(dp));
             for(int i=1;i<=n;i++) if(a[i]==a[i-1]) sum[i]=sum[i-1]+a[i]; else sum[i]=sum[i-1];
             for(int i=1;i<=n;i++)
                for(int j=1;j<i;j++){
                    for(int k=1;k<=j;k++)
                        dp[i][j==i-1?k+1:1]=max(dp[i][j==i-1?k+1:1],dp[j][k]+(i==j+1?0:sum[i-1]-sum[j+1])+(a[i]==a[j]?a[i]:0)+(j==k||i==j+1?0:(a[j+1]==a[j-k-1]?a[j+1]:0)));
             }
             long long maxn=0;
             for(int i=1;i<=n;i++) maxn=max(maxn,dp[n][i]);
             printf("%lld\n",maxn);
        }
    }
    return 0;
}
