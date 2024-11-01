#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;
int t,n,a[200005],maxa,dp[2005][105][105],dpp[200005][12][12],ans;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        ans=maxa=0;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i],maxa=max(maxa,a[i]);
        if(n<=2000&&maxa<=100){
            for(int i=0;i<=n;i++)
                for(int j=0;j<=maxa;j++)
                    for(int k=0;k<=maxa;k++)
                        dp[i][j][k]=-0x3f3f3f3f;
            dp[0][0][0]=0;
            for(int i=0;i<=n;i++)
                for(int j=0;j<=maxa;j++)
                    for(int k=0;k<=maxa;k++){
                        //cout<<i<<","<<j<<","<<k<<" : "<<dp[i][j][k]<<"\n";
                        if(n==i){
                            ans=max(ans,dp[i][j][k]);
                            continue;
                        }
                        dp[i+1][j][a[i+1]]=max(dp[i+1][j][a[i+1]],dp[i][j][k]+(int)(k==a[i+1])*k);
                        //cout<<"("<<i+1<<","<<j<<","<<a[i]<<"):"<<dp[i+1][j][a[i+1]]
                        dp[i+1][a[i+1]][k]=max(dp[i+1][a[i+1]][k],dp[i][j][k]+(int)(j==a[i+1])*j);
                    }
        }
        else{
            for(int i=0;i<=n;i++)
                for(int j=0;j<=maxa;j++)
                    for(int k=0;k<=maxa;k++)
                        dpp[i][j][k]=-0x3f3f3f3f;
            dpp[0][0][0]=0;
            for(int i=0;i<=n;i++)
                for(int j=0;j<=maxa;j++)
                    for(int k=0;k<=maxa;k++){
                        //cout<<i<<","<<j<<","<<k<<" : "<<dp[i][j][k]<<"\n";
                        if(n==i){
                            ans=max(ans,dpp[i][j][k]);
                            continue;
                        }
                        dpp[i+1][j][a[i+1]]=max(dpp[i+1][j][a[i+1]],dpp[i][j][k]+(int)(k==a[i+1])*k);
                        //cout<<"("<<i+1<<","<<j<<","<<a[i]<<"):"<<dp[i+1][j][a[i+1]]
                        dpp[i+1][a[i+1]][k]=max(dpp[i+1][a[i+1]][k],dpp[i][j][k]+(int)(j==a[i+1])*j);
                    }
        }
        cout<<ans<<"\n";
    }
    return 0;
}