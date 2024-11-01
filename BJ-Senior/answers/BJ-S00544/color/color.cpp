#include <iostream>
#include <cstring>
using namespace std;

int T;
long long n,ans;
long long a[200010];
long long dp[2010][2010];

long long point(int x,int y){
    if (a[x] == a[y] && x && y) return a[x];
    else return 0;
}

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> T;
    while (T--){
        cin >> n;
        for (int i = 1;i <= n;i++){
            cin >> a[i];
        }
        memset(dp,0,sizeof(dp));
        ans = 0;
        for (int l1 = 0;l1 <= n;l1++){
            for (int l2 = 0;l2 <= n;l2++){
                if (l1 == l2) continue;
                if (l2 == l1-1) {
                    for (int j = 0;j < l1;j++){
                        if (j != l2) dp[l1][l2] = max(dp[l1][l2],dp[j][l2] + point(j,l1));
                    }
                }
                if (l1 == l2-1){
                    for (int j = 0;j < l2;j++){
                        if (j != l1) dp[l1][l2] = max(dp[l1][l2],dp[l1][j] + point(j,l2));
                    }
                }
                if (l1 != l2-1 && l1 < l2) dp[l1][l2] = max(dp[l1][l2],dp[l1][l2-1] + point(l2-1,l2));
                if (l2 != l1-1 && l2 < l1) dp[l1][l2] = max(dp[l1][l2],dp[l1-1][l2] + point(l1-1,l1));
            }
        }
        for (int i = 1;i < n;i++){
            ans = max(ans,dp[i][n]);
            ans = max(ans,dp[n][i]);
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
