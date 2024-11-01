#include<bits/stdc++.h>
#define pb push_back
#define popcnt __builtin_popcountll
#define debug printf("Passed line %d\n", __LINE__)

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

template<typename T> inline void checkmax(T &x, const T &y){if (x<y) x = y;}

template<typename T> inline void checkmin(T &x, const T &y){if (x>y) x = y;}

const int N = 5e5, ALL = (1<<20)-1, M = 2e5, K = 20;
int dep[N], g[N], tmp[N], ls[N], rs[N], x[4], Max[N], a[M], n, m, k, delta;
ll sum[N];
char c[K][M];
PII ask[N];

void build(int p, int d){
    if (!d) return;
    dep[p] = d;
    build(ls[p] = 2*p, d-1), build(rs[p] = 2*p+1, d-1);
    if (c[d][p^(1<<k-d)] == '1') swap(ls[p], rs[p]);
}

void init(int p, int d){
    g[p] = ALL, Max[p] = 0;
    if (!d){sum[p] = p-delta; return;}
    init(ls[p], d-1), init(rs[p], d-1), sum[p] = sum[ls[p]]+sum[rs[p]];
}

void del(int p, int mx){
    if (!dep[p]){Max[p] = mx; return;}
    del(ls[p], max(dep[p], mx)); del(rs[p], mx);
}

void upd(int p){
    int x, y = 0;
    while (p >>= 1){
        y = (y<<1)|1;
        x = g[ls[p]]&y;
        sum[p] = sum[ls[p]], g[p] = g[ls[p]]^x;
        if (x) g[p] |= g[rs[p]], sum[p] += sum[rs[p]];
    }
}

inline void solve(){
    scanf("%d%d%d%d", &x[0], &x[1], &x[2], &x[3]); for (int i = 1;i<=n;i++) a[i] = tmp[i]^x[i&3], checkmin(a[i], 19);
    init(1, k); int rt = (1<<k), p, lst = 0; ll ans = 0;
    for (int i = 1;i<=m;i++){
        p = ask[i].first;
        if ((1<<dep[rt])<p){
            while ((1<<dep[rt])<p) rt >>= 1;
            del(rt, 0);
            for (int j = (1<<k);j<(1<<k)+lst;j++){
                if (Max[j] > a[j-delta] && sum[j]){
                    sum[j] = 0, upd(j);
                }
            }
        }
        for (int j = lst+1;j<=p;j++){
            g[j+delta] = (1<<a[j]);
            if (Max[j+delta] > a[j]) sum[j+delta] = 0;
            upd(j+delta);
        }
        lst = p;
        ans ^= sum[rt]*ask[i].second;
    }
    printf("%lld\n", ans);
}

int main(){
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    scanf("%d%d", &n, &m), k = __lg(n-1)+1; for (int i = 1;i<=n;i++) scanf("%d", &tmp[i]);
    delta = (1<<k)-1;
    for (int i = 1;i<=m;i++) scanf("%d", &ask[i].first), ask[i].second = i; sort(ask+1, ask+m+1);
    for (int i = 1;i<=k;i++) scanf("%s", c[i]);
    build(1, k);
    int t; scanf("%d", &t); while (t--) solve();
    return 0;
}
/*
self check:
1. long long
2. size of array
3. code for testing
4. initializing
*/