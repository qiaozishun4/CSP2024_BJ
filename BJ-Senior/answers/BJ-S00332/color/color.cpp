#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2005;
const int maxv = (int) 1e18;
int t,n,dp[maxn][2][maxn],arr[maxn];
signed main () {
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld",&n);
        for(int i = 1; i <= n; i++) {
            scanf("%lld",&arr[i]);
        }
        for(int i = 0; i <= n+1; i++) {
            for(int j = 0; j < 2; j++) {
                for(int l = 0; l <= n+1; l++) {
                    dp[i][j][l] = -maxv;
                }
            }
        }
        dp[2][0][0] = 0;
        dp[2][1][0] = 0;
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < 2; j++) {
                for(int l = 0; l <= i; l++) {
                    if(dp[i][j][l] == -maxv) continue;
                    int adjeq = 0;
                    if(arr[i-1] == arr[i]) adjeq = arr[i];
                    dp[i+1][j][l] = max(dp[i+1][j][l],dp[i][j][l]+adjeq);
                    int nvl = 0;
                    if(j == 0) nvl = 1;
                    int dsteq = 0;
                    if(l > 0 && arr[l] == arr[i]) dsteq = arr[i];
                    dp[i+1][nvl][i-1] = max(dp[i+1][nvl][i-1],dp[i][j][l]+dsteq);
                }
            }
        }
        int ans = -maxv;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j <= n; j++) {
                ans = max(ans,dp[n+1][i][j]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}