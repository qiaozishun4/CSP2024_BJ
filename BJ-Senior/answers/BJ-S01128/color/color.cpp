#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[2005],c[2005][2005],dp[2005][2005],ans;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--){
        ans = 0;
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];
        for(int i = 1;i <= n;i++)
            for(int j = i + 1;j <= n;j++){
                c[i][j] = c[i][j - 1];
                if(a[j - 1] == a[j]) c[i][j] += a[j - 1];
            }
        for(int i = 1;i <= n;i++){
            b[i] = 0;
            for(int j = 0;j < i;j++) dp[i][j] = 0;
        }
        for(int i = 2;i <= n;i++){
            dp[i][0] = c[1][i];
            for(int j = 0;j < i - 1;j++)
                if(a[j] != a[i]) dp[i][i - 1] = max(dp[i][i - 1],dp[i - 1][j]);
                else dp[i][i - 1] = max(dp[i][i - 1],dp[i - 1][j] + a[i]);
            for(int j = 1;j < i - 1;j++) dp[i][j] = max(dp[i][j],b[j] + c[j + 1][i]);
            for(int j = 0;j < i;j++)
                if(a[j] == a[i + 1]) b[i] = max(b[i],dp[i][j] + a[i + 1]);
                else b[i] = max(b[i],dp[i][j]);
            //cout << b[i] << '\n';
            //for(int j = 0;j < i;j++) cout << i << '*' << j << '*' << dp[i][j] << ' ';
            //cout << '\n';
        }
        for(int i = 0;i < n;i++) ans = max(ans,dp[n][i]);
        cout << ans << '\n';
    }
    return 0;
}
