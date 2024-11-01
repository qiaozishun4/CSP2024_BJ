#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+5;
int a[N], c[N];
int cham[N];
bool d[20][N];

int work(int tot) {
    int rnd = log2(tot);
    for (int i = 1; i <= rnd; i++) {
        for (int j = 1; j <= tot-1; j += 2) {
            int ia, ib;
            if (a[j] > a[j+1]) ia = j, ib = j+1;
            else ia = j+1, ib = j;
            int aa = max(a[j], a[j+1]), bb = min(a[j], a[j+1]);
            if (d[i][(j+1)/2] == 0) {
                if (bb >= i)
                    a[(j+1)/2] = bb, cham[(j+1)/2] = ib;
                else
                    a[(j+1)/2] = aa, cham[(j+1)/2] = ia;
            }
            else {
                if (aa >= i)
                    a[(j+1)/2] = aa, cham[(j+1)/2] = ia;
                else
                    a[(j+1)/2] = bb, cham[(j+1)/2] = ib;
            }
        }
        tot /= 2;
    }
    return cham[1];
}

signed main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> c[i];
    int k = ceil(log2(n)), k1 = (1 << (k-1));
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k1; j++) {
            char ch;
            cin >> ch;
            d[i][j] = (ch - '0');
        }
        k1 /= 2;
    }
    int T;
    cin >> T;
    while (T--) {
        int x[4];
        int ans = 0;
        for (int i = 0; i < 4; i++) cin >> x[i];
        for (int i = 1; i <= n; i++) a[i] ^= x[i%4];
        for (int i = 1; i <= m; i++) {
            int tot = c[i];
            for (int j = 1; j <= c[i]; j++)
                cham[j] = j;
            int ansi = work(c[i]);
            ans ^= (i * ansi);
        }
        cout << ans << endl;
    }
    return 0;
}