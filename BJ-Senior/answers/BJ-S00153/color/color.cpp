#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 10;
int T,n,a[N],p[N],ans;
int dp[110][110],w[110][110];
void dfs(int step) {
    if(step > n) {
        int preb = 0,prer = 0,cnt = 0;
        for(int i = 1;i <= n;i++) {
            if(p[i]) {
                if(prer && a[i] == a[prer]) cnt += a[i];
                prer = i;
            }
            else {
                if(preb && a[i] == a[preb]) cnt += a[i];
                preb = i;
            }
        }
        ans = max(ans,cnt); return ;
    }
    p[step] = 1; dfs(step + 1);
    p[step] = 0; dfs(step + 1);
}
void solve() {
    cin >> n; ans = 0;
    for(int i = 1;i <= n;i++) cin >> a[i];
    if(n <= 20) { dfs(1); cout << ans << "\n"; return ; }
    if(n <= 200) {
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= i;j++)
                for(int k = j + 1;k <= i;k++)
                    if(a[k] == a[k - 1]) w[j][i] += a[k];
        memset(dp,-0x3f,sizeof(dp)); dp[0][0] = 0;
        for(int i = 1;i <= n;i++) {
            for(int j = 0;j < i;j++) {
                for(int k = 0;k <= 100;k++) {
                    if(j < i - 1) dp[i][a[i - 1]] = max(dp[i][a[i - 1]],dp[j][k] + (a[i] == a[j]) * a[i] + (a[j + 1] == k) * a[j + 1] + w[j + 1][i]);
                    else dp[i][k] = max(dp[j][k] + (a[i] == a[j]) * a[i],dp[i][k]);
                }
            }
        }
        int ans = 0;
        for(int i = 1;i <= 100;i++) ans = max(ans,dp[n][i]);
        cout << ans << "\n";
    }
}
int main() {
    freopen("color.in","r",stdin); freopen("color.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--) solve();
    return 0;
}
