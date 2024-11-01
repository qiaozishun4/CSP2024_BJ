#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, m, a[N], b[N], c[N], d[30][N];
int Play(vector <int> p, int r) {
    if(p.size() == 1) return p[0];
    vector <int> nxt; nxt.clear();
    for(int i = 0; i < p.size() / 2; i++) {
        int _d = d[r][i+1];
        if(_d == 0) {
            if(a[p[2*i]] >= r) nxt.push_back(p[2*i]);
            else nxt.push_back(p[2*i+1]);
        }
        else {
            if(a[p[2*i+1]] >= r) nxt.push_back(p[2*i+1]);
            else nxt.push_back(p[2*i]);
        }
    }
    return Play(nxt, r + 1);
}
int main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for(int i = 1; i <= m; i++) scanf("%d", &c[i]);
    int bak = n, cnt = 0; while(bak) cnt++, bak >>= 1;
    for(int i = 1; i <= cnt; i++) for(int j = 1; j <= (1<<(cnt-i)); j++) { char ch; cin >> ch; d[i][j] = ch - '0'; }
    int T; scanf("%d", &T);
    while(T--) {
        int x[4]; for(int i = 0; i < 4; i++) scanf("%d", &x[i]);
        for(int i = 1; i <= n; i++) a[i] = b[i] ^ x[i%4];
        ll ans = 0;
        for(int i = 1; i <= m; i++) {
            vector <int> p; p.clear();
            for(int j = 1; j <= c[i]; j++) p.push_back(j);
            ans = ans ^ (Play(p, 1) * (ll)i);
        }
        printf("%lld\n", ans);
    }
    return 0;
}