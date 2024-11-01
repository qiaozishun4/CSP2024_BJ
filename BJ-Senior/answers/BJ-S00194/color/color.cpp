#include<bits/stdc++.h>
using namespace std;
int dp[110][110][110][2];
int a[int(1e5+100)],n,ma=0,num,t;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            for(int k=0;k<i;k++){
                if(j==k)continue;
                    dp[i+1][i][k][0]=max(dp[i][j][k][0]+int(a[i]==a[i+1])*a[i+1],dp[i+1][i][k][0]);
                    dp[i+1][j][i][0]=max(dp[i][j][k][1]+int(a[j]==a[i+1])*a[i+1],dp[i+1][j][i][0]);
                    dp[i+1][i][k][1]=max(dp[i][j][k][0]+int(a[k]==a[i+1])*a[i+1],dp[i+1][i][k][1]);
                    dp[i+1][j][i][1]=max(dp[i][j][k][1]+int(a[i]==a[i+1])*a[i+1],dp[i+1][j][i][1]);
            }
        }
    }
    for(int j=1;j<=n;j++){
        for(int k=1;k<=n;k++){
                if(j==k)continue;
            ma=max(ma,dp[n][j][k][0]);
            ma=max(ma,dp[n][j][k][1]);
        }
    }
    cout<<ma<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<i;j++){
            for(int k=0;k<i;k++){
                dp[i][j][k][1]=0;
                dp[i][j][k][0]=0;
            }
        }
    }
    ma=0;
    }
    return 0;
}
