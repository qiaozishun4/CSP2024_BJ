#include <bits/stdc++.h>

using namespace std;

#define sqr(i) ((i) * (i))

const int N = 1e5 + 10, M = 1e6 + 10;

struct car {
    int d, v, a;
} c[N];

bitset <M> p;
int nd[N];

/*
void fl(int l, int r, int flg)
{
    if (flg) {
        for (int i = l; i < r; i++)
            if (p[i])
                nd[i]++;
    } else {
        for (int i = l + 1; i <= r; i++)
            if (p[i])
                nd[i]++;
    }
}
*/

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, m, l, vm, pp, tt = 0;
        pair <int, int> f;
        cin >> n >> m >> l >> vm;
        for (int i = 1; i <= n; i++)
            cin >> c[i].d >> c[i].v >> c[i].a;
        for (int i = 1; i <= m; i++) {
            cin >> pp;
            p[pp] = 1;
        }

        for (int i = 1; i <= n; i++) {
            int d = c[i].d, v = c[i].v, a = c[i].a;
            if (v > vm) {
                tt++;
                for (int j = d; j <= l; j++)
                    if (p[j])
                        nd[j]++;
            }
        }
        sort(nd, nd + l + 1, greater<int>());
        int res = 0;
        for (; nd[res] == nd[0]; res++);
        cout << tt << ' ' << res;
    }
    return 0;
}
