#include<bits/stdc++.h>
using namespace std;
int n;
int a[2010];
int g[2010][2010];
int f[110][110];
int dp[2010];
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T; cin >> T;
    while(T--) {
        cin >> n;
        for(int i=1; i<=n; ++i) cin >> a[i];
        if(n<=15) {
            int ans = 0;
            for(int i=0; i<(1<<n); ++i) {
                int lst0 = -1, lst1 = -1, ths = 0;
                for(int j=1; j<=n; ++j) {
                    if(i&(1<<(j-1))) {
                        if(lst1>=0 && a[j]==a[lst1]) ths += a[j];
                        lst1 = j;
                    }else {
                        if(lst0>=0 && a[j]==a[lst0]) ths += a[j];
                        lst0 = j;
                    }
                }ans = max(ans, ths);
            } cout << ans << '\n';
        }
        else if(n<=100){
            memset(g, 0, sizeof(g));
            memset(f, 0, sizeof(f));
            for(int i=1; i<=n; ++i) {
                for(int j=i+1; j<=n; ++j) {
                    for(int k=i+1; k<=j; ++k) {
                        if(a[k]==a[k-1]) g[i][j] += a[k];
                    }
                }
            }
            int ans = 0;
            for(int i=1; i<=n; ++i) {
                for(int j=1; j<i; ++j) {
                    f[i][j] = g[j+1][i];
                    for(int k=1; k<j; ++k) {
                        f[i][j] = max(f[i][j], f[j][k] + g[j+1][i] + ((bool)(a[k]==a[j+1]))*a[k]);
                        ans = max(ans, f[i][j]);
                    }
                }
            }cout << ans << '\n';
        }else {
            memset(g, 0, sizeof(g));
            memset(f, 0, sizeof(f));
            for(int i=1; i<=n; ++i) {
                for(int j=i+1; j<=n; ++j) {
                    g[i][j] = g[i][j-1];
                    if(a[j]==a[j-1]) g[i][j] += a[j];
                }
            }
            for(int i=1; i<=n; ++i) {
                dp[i] = g[1][i];
                for(int j=1; j<i; ++j) {
                    dp[i] = max(dp[i], dp[j]+((bool)(a[j]==a[i+1]))*a[j]+g[j+1][i]);
                }
            }cout << dp[n] << '\n';
        }
    }
    return 0;
}