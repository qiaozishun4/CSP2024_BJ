#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
const int maxn = 2e5 + 10;
const int maxrnd = 100 + 10;
int n, k, q, mx, mxr, cnt[maxn], ans[maxn];
bool occur[maxn];
vector<int> a[maxn];
vector<pair<int, int> > pos[maxn], qr[maxrnd];
vector<bool> vis[2][maxn];
void init() {
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) a[i].clear();
    mx = 0;
    for (int i = 1; i <= n; i++) {
        int num; cin >> num;
        for (int j = 0; j < num; j++) {
            int x; cin >> x;
            a[i].push_back(x);
            mx = max(mx, x);
        }
    }
    for (int i = 0; i <= mx; i++) pos[i].clear();
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < SZ(a[i]); j++)
            pos[a[i][j]].push_back({i, j});
    for (int i = 0; i <= 100; i++) qr[i].clear();
    mxr = 0;
    for (int i = 1; i <= q; i++) {
        int r, c; cin >> r >> c;
        qr[r].push_back({i, c});
        mxr = max(mxr, r);
    }
}
void solve() {
    memset(ans, 0, sizeof(ans));
    for (int p = 0; p <= 1; p++)
        for (int i = 1; i <= n; i++) {
            vis[p][i].clear();
            vis[p][i].resize(SZ(a[i]), 0);
        }
    for (auto x : pos[1]) vis[0][x.first][x.second] = 1;
    for (int rnd = 1; rnd <= 100; rnd++) {
        memset(cnt, 0, sizeof(cnt));
        memset(occur, 0, sizeof(occur));
        for (int i = 1; i <= n; i++) {
            for (int pre = -1, j = 0; j < SZ(a[i]); j++) {
                if (pre >= 0 && j - pre < k && !occur[a[i][j]]) {
                    occur[a[i][j]] = 1;
                    if (cnt[a[i][j]] < 2) {
                        for (auto x : pos[a[i][j]]) if (x.first != i) vis[1][x.first][x.second] = 1;
                        cnt[a[i][j]]++;
                    }
                }
                if (vis[0][i][j]) pre = j;
            }
            for (int x : a[i]) occur[x] = 0;
        }
        for (auto x : qr[rnd]) ans[x.first] = (0 <= x.second && x.second <= mx && cnt[x.second] > 0) ? 1 : 0;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < SZ(a[i]); j++) {
                vis[0][i][j] = vis[1][i][j];
                vis[1][i][j] = 0;
            }
    }
    for (int i = 1; i <= q; i++) cout << (ans[i] ? 1 : 0) << "\n";
}
int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        init();
        solve();
    }
    return 0;
}
