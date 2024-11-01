#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int N = 1e3 + 5, M = 1e6 + 5;
int n, m, k, x, y, d, a[M], ans; char c[N][N];
void solve() {
    cin>>n>>m>>k>>x>>y>>d; 
    ans = 0; for(int i = 1; i <= n * m; i++) a[i] = 0; a[(x - 1) * m + y] = 1;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin>>c[i][j];
    while(k--) {
        int xx = x, yy = y;
        if(d == 0) yy++;
        else if(d == 1) xx++;
        else if(d == 2) yy--;
        else if(d == 3) xx--;
        if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && c[xx][yy] == '.') x = xx, y = yy;
        else d = (d + 1) % 4; 
        // cout<<"goto "<<x<<" "<<y<<" "<<d<<" "<<k<<endl;
        a[(x - 1) * m + y] = 1;
    }
    for(int i = 1; i <= n * m; i++) ans += a[i];
    cout<<ans<<endl;
    return;
}
signed main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}