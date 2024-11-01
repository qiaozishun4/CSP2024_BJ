#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const int L = 1e6 + 5;
const ll inf = 1e18 + 5;
int T;
int n;
int a[N];
inline int read() {
    int w = 0;
    char ch = '#';
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
    return w;
}
ll d[L * 4];
ll z[L * 4];
int len = 1e6 + 1;
void pushdown(int p) {
    if(z[p]) {
        d[p * 2] += z[p];
        d[p * 2 + 1] += z[p];
        z[p * 2] += z[p];
        z[p * 2 + 1] += z[p];
        z[p] = 0;
    }
}
void build(int s, int t, int p) {
    z[p] = 0;
    if(s == t) {
        d[p] = (s == len) ? 0 : -inf;
        return;
    }
    int mid = (s + t) >> 1;
    build(s, mid, p * 2);
    build(mid + 1, t, p * 2 + 1);
    d[p] = max(d[p * 2], d[p * 2 + 1]);
}
ll getval(int i, int s, int t, int p) {
    if(s == t) return d[p];
    int mid = (s + t) >> 1;
    pushdown(p);
    if(i <= mid) return getval(i, s, mid, p * 2);
    return getval(i, mid + 1, t, p * 2 + 1);
}
void chkmaxval(int i, ll v, int s, int t, int p) {
    if(s == t) {
        d[p] = max(d[p], v);
        return;
    }
    int mid = (s + t) >> 1;
    pushdown(p);
    if(i <= mid) chkmaxval(i, v, s, mid, p * 2);
    else chkmaxval(i, v, mid + 1, t, p * 2 + 1);
    d[p] = max(d[p * 2], d[p * 2 + 1]);
}
ll ans = 0;
void Findans(int s, int t, int p) {
    if(s == t) {
        ans = max(ans, d[p]);
        return;
    }
    pushdown(p);
    int mid = (s + t) >> 1;
    Findans(s, mid, p * 2);
    Findans(mid + 1, t, p * 2 + 1);
}
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    T = read();
    a[1] = len;
    for(int ti = 1; ti <= T; ti++) {
        n = read() + 1;
        for(int i = 2; i <= n; i++) a[i] = read();
        build(1, len, 1);
        a[1] = len;
        for(int i = 2; i < n; i++) {
            ll nwdp = max(d[1], getval(a[i + 1], 1, len, 1) + a[i + 1]);
            if(a[i] == a[i + 1]) {
                z[1] += a[i + 1], d[1] += a[i + 1];
            }
            chkmaxval(a[i], nwdp, 1, len, 1);
        }
        ans = 0;
        Findans(1, len, 1);
        printf("%lld\n", ans);
    }
    return 0;
}
