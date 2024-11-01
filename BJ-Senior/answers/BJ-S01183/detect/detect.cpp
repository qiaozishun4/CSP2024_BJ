#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#define maxn 1000005

#define fopen(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);

#ifdef int
#define inf 0x3f3f3f3f3f3f3f3fll
#else
#define inf 0x3f3f3f3f
#endif

using namespace std;

int n, m, l, v, p, cnt[maxn], lst[maxn], sum, ans;

struct node {
    int l, r;
    bool operator<(node b)const {
        return l < b.l;
    }
} a[maxn];

int qr(int l, int r) {
    if(l > r) return 0;
    r = min(r, 1000000);
    return (l <= 0) ? cnt[r] : cnt[r] - cnt[l - 1];
}

void work() {
    queue<int> q;
    for(int i = 0; i <= 1000000; i++) cnt[i] = 0;
    sum = ans = 0;
    cin >> n >> m >> l >> v;
    for(int i = 1; i <= n; i++) {
        int d, x, g;
        cin >> d >> x >> g;
        if(g == 0) {
            if(x > v) a[i].l = d, a[i].r = 1000000;
            else a[i].l = a[i].r = 1000001;
        }
        else if(g > 0) {
            a[i].l = d + floor(1.0 * (v * v - x * x) / g / 2 + 1);
            a[i].r = 1000000;
            a[i].l = max(a[i].l, d); a[i].l = min(a[i].l, 1000001);
        }
        else {
            a[i].l = d;
            a[i].r = d + ceil(1.0 * (v * v - x * x) / g / 2 - 1);
            // cout << a[i].r << "^\n";
            a[i].r = max(a[i].r, d - 1); a[i].r = min(a[i].r, 1000000);
        }
    }
    for(int i = 1; i <= m; i++) cin >> p, cnt[p]++;
    for(int i = 0; i <= 1000000; i++) {
        if(i == 0 && cnt[i] > 0) lst[i] = 0;
        else if(i == 0) lst[i] = -1;
        else {
            if(cnt[i] > 0) lst[i] = i;
            else lst[i] = lst[i - 1];
        } 
    }
    for(int i = 1; i <= 1000000; i++) cnt[i] += cnt[i - 1];
    sort(a + 1, a + n + 1);
    int p = -1, mn = inf;
    for(int i = 1; i <= n; i++) {
        // cout << a[i].l << '~' << a[i].r << '\n';
        if(qr(a[i].l, a[i].r) > 0) sum++; 
        else continue;
        // cout << "qr" << a[i].l << '~' << a[i].r << ' ' << p << ' ' << mn << '\n';
        if(qr(a[i].l, mn) <= 0) {
            ans++;
            p = mn;
            mn = inf;
        }
        if(a[i].l > p) mn = min(mn, lst[a[i].r]);
    }
    if(mn < inf) ans++;
    cout << sum << ' ' << m - ans << '\n';
}

signed main() {
    fopen("detect");
    ios::sync_with_stdio(false); cin.tie(0);
    int _; cin >> _; while(_--) work();
}