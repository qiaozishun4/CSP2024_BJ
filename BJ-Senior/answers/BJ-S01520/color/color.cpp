#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int T;
int n,a[N],dp[N][4],la[N],c[N],sum[N];
map<int,int> mp;
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        memset(c,0,sizeof(c));
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        mp.clear();
        scanf("%lld",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++){
            if(mp.count(a[i])){
                la[i]=mp[a[i]];
                mp[a[i]]=i;
            }else{
                la[i]=0;
                mp[a[i]]=i;
            }
        }
        for(int i=2;i<=n;i++){
            if(a[i]==a[i-1]) c[i]=a[i];
            sum[i]=sum[i-1]+c[i];
        }
        dp[2][3]=dp[2][1]=(a[1]==a[2]?a[1]:0);
        for(int i=3;i<=n;i++){
            dp[i][0]=max(dp[i-1][1],dp[i-1][2]+(a[i]==a[i-2]?a[i]:0));
            dp[i][1]=max(dp[i-1][1]+(a[i]==a[i-1]?a[i]:0),dp[i-1][2]+(a[i]==a[i-1]?a[i]:0));
            dp[i][2]=max(dp[i-1][0]+(a[i]==a[i-2]?a[i]:0),dp[i-1][3]);
            dp[i][3]=max(dp[i-1][0]+(a[i]==a[i-1]?a[i]:0),dp[i-1][3]+(a[i]==a[i-1]?a[i]:0));
            if(la[i]!=0){
                dp[i][0]=max(dp[i][0],dp[la[i]+1][2]+sum[i-1]-sum[la[i]+1]+a[i]);
                dp[i][2]=max(dp[i][2],dp[la[i]+1][0]+sum[i-1]-sum[la[i]+1]+a[i]);
            }
        }
        int ans=0;
        for(int i=0;i<4;i++) ans=max(ans,dp[n][i]);
        printf("%lld\n",ans);
    }
    return 0;
}