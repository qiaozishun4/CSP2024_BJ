#include<bits/stdc++.h>
using namespace std;
int t,n,a[105],sum[105][105],dp[105][105];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        memset(sum,0,sizeof(sum));memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                sum[i][j]=sum[i][j-1];
                if(j>i&&a[j]==a[j-1]) sum[i][j]+=a[j];
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=i-1;j++){
                for(int k=0;k<=j-1;k++){
                    if(a[k]==a[j+1]) dp[i][j]=max(dp[i][j],dp[j][k]+sum[j+1][i]+a[k]);
                    else dp[i][j]=max(dp[i][j],dp[j][k]+sum[j+1][i]);
                }
                if(i==n) ans=max(ans,dp[i][j]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}