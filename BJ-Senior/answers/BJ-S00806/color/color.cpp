# include <bits/stdc++.h>
using namespace std;
# define int long long
const int MAXN = 2e5 + 10, MAXM = 1e6 + 10;
int T, n, a[MAXN], f[MAXN], mx[MAXM], maxx, tag;
int read() {
    int x = 0; bool f = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
		if (ch == '-') f = 1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - 48;
        ch = getchar();
    }
    return (f ? -1 : 1) * x;
}
signed main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    T = read();
    while (T--) {
        n = read();
        memset(mx, -0x3f, sizeof mx);
        for (int i = 1; i <= n; i++) a[i] = read();
        memset(f, -0x3f, sizeof f);
        f[0] = 0;
        maxx = 0;
        tag = 0;
        for (int i = 2; i <= n; i++) {
            int ntag = tag + (a[i] == a[i - 1] ? a[i] : 0);
            f[i - 1] = max(maxx + tag, mx[a[i]] + tag + a[i]) - ntag;
            maxx = max(maxx, f[i - 1]);
            mx[a[i - 1]] = max(mx[a[i - 1]], f[i - 1]);
            tag = ntag;
            //for (int j = 0; j < i; j++) cout << f[j] + tag << " " ;
            //cout << endl ;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans =max(ans, f[i] + tag);
        }
        cout << ans << endl ;
    }
    return 0;
}