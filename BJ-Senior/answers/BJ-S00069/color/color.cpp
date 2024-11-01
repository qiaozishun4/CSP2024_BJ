#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+7;
int n;
int a[maxn];
int dp[2007][2007];//i,lst_red,lst_blue
inline void slv(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=0;
    for(int i=1;i<=n;i++){
        // i -> red
        for(int l=0;l<i;l++){
            dp[i][l]=max(dp[i][l],dp[i-1][l]+(a[i]==a[i-1])*a[i]);
            dp[i][i-1]=max(dp[i][i-1],dp[l][i-1]+(a[i]==a[l])*a[i]);
        }
        //i -> blue
        for(int l=0;l<i;l++){
            dp[i-1][i]=max(dp[i-1][i],dp[i-1][l]+(a[i]==a[l])*a[i]);
            dp[l][i]=max(dp[l][i],dp[l][i-1]+(a[i]==a[i-1])*a[i]);
        }
    }
    int ans=0;
    for(int k=0;k<n;k++)ans=max(ans,dp[n][k]);
    for(int k=0;k<n;k++)ans=max(ans,dp[k][n]);
    cout<<ans<<endl;
    return;
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t=0;
    cin>>t;
    while(t--)slv();
}