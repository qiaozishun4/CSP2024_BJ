#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int inf = 1e9;
typedef long long LL;
int T, n, m, dp[N];
LL L, V, p[N];
struct Car{
    LL d, v, a;
    LL l, r;
} x[N];
bool check(int i, int pos) {
    LL s = p[pos]-x[i].d;
    if (s < 0) return 0;
    LL tmp = x[i].v*x[i].v+2*x[i].a*s;
    if (tmp < 0) return 0;
    if (tmp > V*V) return 1;
    else return 0;
}
int b_s1(int idx, int l, int r) {
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(idx, mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}
int b_s2(int idx, int l, int r) {
    while (r-l > 1) {
        int mid = (l + r) / 2;
        if (check(idx, mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}
bool cmp(Car A, Car B) {
    if (A.l == B.l) return A.r < B.r;
    else return A.l < B.l;
}
vector<int> C[N];
void solve() {
    int cnt = 0;
    for(int i = 1; i <= m; i++) C[i].clear();
    for(int i = 1; i <= n; i++) {
        if (x[i].d > p[m]) continue;
        if (x[i].a == 0) {
            if (x[i].v > V) {
                x[i].l = lower_bound(p+1, p+1+m, x[i].d)-p;
                x[i].r = m;
                cnt++;
            } else x[i].l = x[i].r = 0;
        } else if (x[i].a > 0) {
            if (check(i, m)) {
                int pos = lower_bound(p+1, p+1+m, x[i].d)-p;
                x[i].l = b_s1(i, pos-1, m), x[i].r = m;
                cnt++;
            } else x[i].l = x[i].r = 0;
        } else {
            int pos = lower_bound(p+1, p+1+m, x[i].d)-p;
            if (check(i, pos)) {
                x[i].l = pos, x[i].r = b_s2(i, pos, m+1);
                cnt++;
            } else x[i].l = x[i].r = 0;
        }
        C[x[i].r].push_back(x[i].l);
    }
    int ans = 0;
    dp[0] = 0;
    for(int i = 1; i <= m; i++) {
        dp[i] = dp[i-1];
        for(int j = 0; j < C[i].size(); j++) {
            int idx = C[i][j];
            dp[i] = max(dp[i], 1+dp[idx-1]);
        }
        ans = max(ans, dp[i]);
    }
    printf("%d %d\n", cnt, m-ans);
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while (T--) {
        scanf("%d%d%lld%lld", &n, &m, &L, &V);
//        cin >> n >> m >> L >> V;
        for(int i = 1; i <= n; i++) {
            scanf("%lld%lld%lld", &x[i].d, &x[i].v, &x[i].a);
        }
        for(int i = 1; i <= m; i++) {
            scanf("%lld", &p[i]);
        }
        solve();
    }
    return 0;
}
