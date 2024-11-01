#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[100009];
ll dp[100009][3];int color[100009];int ans=0;
ll n;void dfs(int curr,int sum){
    if(curr==n+1){ans=max(ans,sum);return;}
    int t=0;
for(int i=curr-1;i>=1;i--){
    if(color[i]==1&&arr[i]==arr[curr]){
        t=arr[i];
        break;
    }
}
color[curr]=1;
dfs(curr+1,sum+t);
for(int i=curr-1;i>=1;i--){
    if(color[i]==0&&arr[i]==arr[curr]){
        t=arr[i];
        break;
    }
}
color[curr]=0;
dfs(curr+1,sum+t);
}
void slv(){
    dp[1][0]=0,dp[1][1]=0;
   // for(int i=1;i<=n;i++){
    //  for(int j=1;j<i;j++){
       //dp[i][0]=max(dp[i][0],max(dp[j][0]+(arr[i]==arr[j])*arr[i],dp[j][1]+(arr[i]==arr[j])*arr[i]));
   //    dp[i][1]=max(dp[i][1],max(dp[j][1]+(arr[i]==arr[j])*arr[i],dp[j][0]+(arr[i]==arr[j])*arr[i]));
   //   }
  //  }
   // cout<<max(dp[n][0],dp[n][1])<<endl;
   memset(color,0,sizeof color);ans=0;
   dfs(0,0);

   cout<<ans<<endl;
}


int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
       memset(dp,0,sizeof dp);
        cin>>n;
        for(int i=1;i<=n;i++)cin>>arr[i];
        slv();
    }
    return 0;
}
