#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb emplace_back
#define F(n) for(int i = 1; i <= n; i++)
#define Fi(i, n) for(int i = 1; i <= n; i++)
#define Fx(i, n) for(int i = n; i >= 1; i--)
#define Fn(i, l, r) for(int i = l; i <= r; i++)
#define Fnx(i, l, r) for(int i = r; i >= l; i--)
int T, n, a[200005];
int dp[2][2][200005];
void solve(){
    cin >> n;
    F(n) cin >> a[i];
    memset(dp, 0, sizeof(dp));
    F(n){
        dp[i%2][0][i-1] = 0;
        dp[i%2][1][i-1] = 0;
        Fi(j, i-2){
            dp[i%2][0][j] = dp[(i-1)%2][0][j] + (int)(a[i] == a[i-1])*a[i];
            dp[i%2][0][i-1] = max(dp[i%2][0][i-1], dp[(i-1)%2][1][j] + (int)(a[i] == a[j])*a[i]);
            dp[i%2][1][j] = dp[(i-1)%2][1][j] + (int)(a[i] == a[i-1])*a[i];
            dp[i%2][1][i-1] = max(dp[i%2][1][i-1], dp[(i-1)%2][0][j] + (int)(a[i] == a[j])*a[i]);
        }
    }
    int ans = 0;
    F(n-1){
        ans = max({ans, dp[n%2][0][i], dp[n%2][1][i]});
    }
    cout << ans << endl;
}
signed main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> T;
    F(T) solve();
    return 0;
}
//zha pian mi huo xing wei da shang
//mian
//freopen("color.in", "w", stdin)
//feropen("luogu")
//kkksc03
//chen_zhe
//rteurn 0;
//pbds
