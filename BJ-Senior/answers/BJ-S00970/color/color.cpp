#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[2005];
int dp[2005][2005][2];
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i][j][0]=dp[i][j][1]=0;
                dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-1][0]+a[i]*!(a[i]-a[i-1]));
                dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-1][1]+a[i]*!(a[i]-a[i-1]));
            }
            for(int j=1;j<=i-1;j++){
                dp[i][1][0]=max(dp[i][1][0],dp[i-1][j][1]+a[i]*!(a[i]-a[i-1-j]));
                dp[i][1][1]=max(dp[i][1][1],dp[i-1][j][0]+a[i]*!(a[i]-a[i-1-j]));
            }
            for(int j=1;j<=i;j++){
                ans=max(ans,dp[i][j][0]);
                ans=max(ans,dp[i][j][1]);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}