//LMY bao you bao li bie gua!!!~~~
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int NR = 1e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, a[NR];
bool col[NR];
void dfs(int step, ll &ans){
    if (step > n){
        ll tmp = 0;
        for (int i = 1; i <= n; i++){
            for (int j = i - 1; j >= 1; j--){
                if (col[j] == col[i]){
                    tmp += 1ll * bool(a[i] == a[j]) * a[i];
                    break;
                }
            }
        }
        ans = max(ans, tmp);
        return;
    }
    col[step] = true;
    dfs(step + 1, ans);
    col[step] = false;
    dfs(step + 1, ans);
}
void pts20(){
    ll ans = 0;
    dfs(1, ans);
    cout << ans << endl;
}
ll dp[2005][2005], s[NR];
void pts35(){
    for (int i = 1; i <= n; i++){
        s[i] = s[i - 1] + 1ll * bool(a[i] == a[i - 1]) * a[i];
    }
    memset(dp, ~INF, sizeof dp);
    dp[1][1] = 0;
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= i; j++){
            if (j == 1){
                dp[i][j] = max(dp[i][j], s[i] - s[j]);
            }
            else{
                for (int k = 1; k <= j - 1; k++){
                    //[...k-1][k...j-1][j...i]
                    ll tmp = s[i] - s[j] + dp[j - 1][k] + 1ll * (a[k - 1] == a[j]) * a[j];
                    dp[i][j] = max(dp[i][j], tmp);
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
}
ll F[NR], g[2005][2005];
void pts50(){
    for (int i = 1; i <= n; i++){
        s[i] = s[i - 1] + 1ll * bool(a[i] == a[i - 1]) * a[i];
    }
    memset(dp, ~INF, sizeof dp);
    memset(F, ~INF, sizeof F);
    memset(g, ~INF, sizeof g);
    dp[1][1] = F[1] = 0;
    g[1][0] = 0;
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= i; j++){
            if (j == 1){
                dp[i][j] = s[i] - s[j];
            }
            else{
                dp[i][j] = max(dp[i][j], F[j - 1] + s[i] - s[j]);
                dp[i][j] = max(dp[i][j], s[i] - s[j] + g[j - 1][a[j]] + a[j]);
            }
            F[i] = max(F[i], dp[i][j]);
            g[i][a[j - 1]] = max(g[i][a[j - 1]], dp[i][j]);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
}
void test(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if (n <= 15){
        pts20();
        return;
    }
    if (n <= 100){
        pts35();
        return;
    }
    if (n <= 2000){
        pts50();
        return;
    }
}
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        test();
    }
    return 0;
}
