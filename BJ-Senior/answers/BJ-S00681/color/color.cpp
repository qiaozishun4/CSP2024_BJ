

#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, a[200020], f[2][200020][2];
inline void solve(){
    memset(a, 0, sizeof(a));
    memset(f, 0, sizeof(f));
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    f[0][0][0] = f[0][0][1] = 0;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < i - 1; j++){
            if(!j || a[i] != a[j]) f[1][i - 1][0] = max(f[1][i - 1][0], f[0][j][1]), f[1][i - 1][1] = max(f[1][i - 1][1], f[0][j][0]);
            else f[1][i - 1][0] = max(f[1][i - 1][0], f[0][j][1] + a[i]), f[1][i - 1][1] = max(f[1][i - 1][1], f[0][j][0] + a[i]);
        }
        for(int j = 0; j < i - 1; j++){
            if(a[i] != a[i - 1]) f[1][j][0] = max(f[1][j][0], f[0][j][0]), f[1][j][1] = max(f[1][j][1], f[0][j][1]);
            else f[1][j][0] = max(f[1][j][0], f[0][j][0] + a[i]), f[1][j][1] = max(f[1][j][1], f[0][j][1] + a[i]);
        }
        for(int j = 0; j <= n; j++){
            f[0][j][0] = f[1][j][0], f[0][j][1] = f[1][j][1]; 
            f[1][j][0] = f[1][j][1] = 0;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, max(f[0][i][0], f[0][i][1]));
    cout << ans << '\n';
}

signed main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}