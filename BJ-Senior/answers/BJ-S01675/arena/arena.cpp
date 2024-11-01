#include<bits/stdc++.h>
using namespace std;
int t,dp[2005][2][2005],a[2005],n;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        memset(dp,0,sizeof(dp));
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
            for(int j=0;j<=1;j++)
                for(int k=0;k<=1;k++)
                    for(int l=1;l<i;l++)
                        if(j==k){
                            int cnt=0;
                            if(a[i]==a[i-1]) cnt=a[i];
                            dp[i][j][l]=max(dp[i][j][l],dp[i-1][j][l]+cnt);
                        }else{
                            int cnt=0;
                            if(a[i]==a[l]) cnt=a[i];
                            dp[i][j][i-1]=max(dp[i][j][i-1],dp[i-1][j][l]+cnt);
                        }
        int ans=0;
        for(int i=0;i<=1;i++)
            for(int j=1;j<n;j++) ans=max(ans,dp[n][i][j]);
        cout<<ans<<endl;
    }
}
