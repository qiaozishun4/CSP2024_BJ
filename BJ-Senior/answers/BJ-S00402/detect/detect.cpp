# include <iostream>
# include <algorithm>
# include <fstream>
using namespace std;
const int MAXN = 100005;
struct Car
{
    double d, v, a;
} c[MAXN];
int t;

bool cmp (Car x, Car y)
{
    if (x.d != y.d)
        return x.d < y.d;
    if (x.v != y.d)
        return x.v < y.v;
    return x.a < y.a;
}

int main ()
{
    freopen ("detect.in", "r", stdin);
    freopen ("detect.out", "w", stdout);
    cin >> t;
    for (int x = 1; x <= t; x++)
    {
        int n, m, l, v, p[MAXN];
        int ans1 = 0, ans2 = 0;
        cin >> n >> m >> l >> v;
        for (int i = 1; i <= n; i++)
            cin >> c[i].d >> c[i].v >> c[i].a;
        for (int i = 1; i <= m; i++)
            cin >> p[i];
        sort (c + 1, c + n + 1, cmp);
        for (int i = 1; i <= n; i++)
            if (c[i].v > v)
                if (c[i].d <= p[m])
                    ans1++;
        if (ans1 == 0)
            ans2 = m;
        else ans2 = m - 1;
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}