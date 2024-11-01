#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#define int long long
#define maxn 1000005

#define fopen(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);

#ifdef int
#define inf 0x3f3f3f3f3f3f3f3fll
#else
#define inf 0x3f3f3f3f
#endif

using namespace std;

int n, a[maxn], f[maxn], g[maxn], p, sum, ans;

void work() {
    sum = ans = 0;
    p = 1;
    for(int i = 0; i <= 1000000; i++) f[i] = g[i] = -inf;
    a[0] = -1;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[p];
        if(a[p] == a[p - 1]) sum += a[p];
        else p++;
    }
    n = p - 1;
    f[0] = 0;
    for(int i = 1; i <= n; i++) {
        f[i] = max(f[i - 1], g[a[i]] + a[i]);
        g[a[i - 1]] = max(g[a[i - 1]], f[i]);
        ans = max(ans, f[i]);
        // cout << f[i] << ' ';
    }//cout << '\n';
    cout << ans + sum << '\n';
}

signed main() {
    fopen("color");
    ios::sync_with_stdio(false); cin.tie(0);
    int _; cin >> _; while(_--) work();
}