#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, a[N];
bool vis[N] = {};
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int l = 1; l <= n; l++) {
        if (vis[l]) continue;
        for (int r = l + 1; r <= n; r++) {
            if (vis[r]) continue;
            if (a[r] > a[l]) {
                ans++;
                vis[l] = 1;
                vis[r] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) 
        if (!vis[i]) ans++;
    cout << ans;
    return 0;
}