#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int maxn = 2e4+5;
int T,n,a[maxn],dp[maxn][maxn],ans;
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        ans = 0;
        memset(dp,0,sizeof(dp));
        cin>>n;
        for(int i = 1 ; i <= n ; i++){
            cin>>a[i];
            for(int j = i-2 ; j >= 0 ; j--){
                dp[j][i] = max(dp[j][i],dp[j][i-1] + (a[i] == a[i-1]?a[i]:0));
                dp[i][i-1] = max(dp[i][i-1],dp[j][i-1] + (a[i] == a[j]?a[i]:0));
                //cout<<i<<" "<<j<<" "<<dp[i][i-1]<<endl;
            }
            for(int k = i-2 ; k >= 0 ; k--){
                dp[i-1][i] = max(dp[i-1][i],dp[i-1][k] + (a[i] == a[k]?a[i]:0));
                dp[i][k] = max(dp[i][k],dp[i-1][k] + (a[i] == a[i-1]?a[i]:0));
                //cout<<i<<" "<<k<<" "<<dp[i-1][i]<<endl;
            }
        }
        //for(int i = 1 ; i <= n ; i++)cout<<dp[i][n-1]<<" "<<dp[n-1][i]<<endl;
        for(int i = n-1 ; i >= 0 ; i--)ans = max(ans,max(dp[i][n],dp[n][i]));
        cout<<ans<<endl;
    }
    return 0;
}
