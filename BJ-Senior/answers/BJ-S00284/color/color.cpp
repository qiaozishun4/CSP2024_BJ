#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=1e6+10;
int T,n,a[N],sum[N],t[M],pre[N];
long long dp[N][2][2];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        memset(t,0,sizeof(t));
        memset(sum,0,sizeof(sum));
        memset(dp,0,sizeof(dp));
        memset(pre,0,sizeof(pre));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum[i]=sum[i-1];
            pre[i]=t[a[i]];
            t[a[i]]=i;
            if(i>1&&a[i]==a[i-1])sum[i]+=a[i];
        }
        for(int i=2;i<=n;i++){
            int tmp=0;
            if(a[i]==a[i-1])tmp=a[i];
            dp[i][0][0]=max(dp[i-1][0][0],dp[i-1][1][0])+tmp;
            dp[i][1][1]=max(dp[i-1][0][1],dp[i-1][1][1])+tmp;
            dp[i][0][1]=max(dp[i-1][0][0],dp[i-1][1][0]);
            dp[i][1][0]=max(dp[i-1][0][1],dp[i-1][1][1]);
            if(pre[i]==0||pre[i]==i-1)continue;
            tmp=0;
            if(pre[i]!=i-1)tmp=a[i];
            dp[i][0][1]=max(dp[i][0][1],dp[pre[i]+1][1][0]+max(sum[i-1]-sum[pre[i]+1],0)+tmp);
            dp[i][1][0]=max(dp[i][1][0],dp[pre[i]+1][0][1]+max(sum[i-1]-sum[pre[i]+1],0)+tmp);

        }
        printf("%lld\n",max(max(dp[n][0][1],dp[n][0][0]),max(dp[n][1][0],dp[n][1][1])));
    }
    return 0;
}
