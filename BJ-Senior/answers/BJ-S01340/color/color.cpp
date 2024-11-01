#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n;
int a[N];
ll dp[2][N];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%lld",&a[i]);
        }
        memset(dp,0ll,sizeof(dp));
        for(int i=1;i<=n;++i){
            dp[i&1][i]=dp[(i-1)&1][0];
            for(int j=0;j<=i-1;++j){
                dp[i&1][j]=dp[(i-1)&1][j]+a[i]*(a[i]==a[i-1]);
            }
            for(int j=1;j<i;++j){
                dp[i&1][i]=max(dp[i&1][i],dp[(i-1)&1][j]+a[i]*(a[i]==a[j-1]));
            }
        }
        ll ans=0;
        for(int j=0;j<=n;++j){
            ans=max(ans,dp[n&1][j]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}