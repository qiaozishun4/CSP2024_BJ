#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int N = 1e5 + 5;

struct Cars
{
    int d, v, a;
} tc[N];

int p[N];

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    for (int tst = 1; tst <= T; tst++)
    {
        int n, m, L, V;
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++)
            cin >> tc[i].d >> tc[i].v >> tc[i].a;
        for (int i = 1; i <= m; i++)
            cin >> p[i];
        cout << n << " " << m << "\n";
    }
    return 0;
}
