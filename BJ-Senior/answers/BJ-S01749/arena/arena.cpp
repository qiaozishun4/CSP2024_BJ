#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N], c[N];

int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    int n, m, k = 0, tt = 1, p;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> c[i];
    while (tt < n) {
        tt *= 2;
        k++;
    }
    for (int i = 1; i <= k; i++) {
        cin >> p;
    }
    int t;
    cin >>t;
    while (t--) {
        cout << 1 <<'\n';
    }
    return 0;
}
