#include<iostream>//50pts
#include<vector>
#include<cstring>
using namespace std;
#define int long long
const int maxn=2020;
int T,n,a[maxn],ans;
vector<int>dp[maxn][maxn];
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)for(int j=0;j<=n;j++)
            if(i!=j)dp[i][j].resize(1);else dp[i][j].resize(n+1);
        for(int i=1;i<=n;i++){for(int j=0;j<=i;j++){
            if(i-j>1)dp[i][j][0]=dp[i-1][j][0]+(a[i]==a[i-1])*a[i],ans=max(ans,dp[i][j][0]);
            else if(i-j==1){
                for(int k=0;k<i-1;k++)dp[i][j][0]=max(dp[i][j][0],dp[i-1][j][k]+(a[i]==a[k])*a[i]);ans=max(ans,dp[i][j][0]);
            }
            else{
                for(int k=0;k<i-1;k++)dp[i][j][k]=dp[i-1][j-1][k]+(a[i]==a[i-1])*a[i],ans=max(ans,dp[i][j][k]);
                for(int k=0;k<i-1;k++)dp[i][j][i-1]=max(dp[i][j][i-1],dp[i-1][k][0]+(a[i]==a[k])*a[i]),ans=max(ans,dp[i][j][i-1]);
            }
        }
        /*cout<<ans<<"\n";*/}
        for(int i=1;i<=n;i++)for(int j=0;j<dp[n][i].size();j++)ans=max(ans,dp[n][i][j]);
        cout<<ans<<"\n";
    }
    return 0;
}