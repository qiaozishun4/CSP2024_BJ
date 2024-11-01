// T2 40分 正解困难
# include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 7;
int cs[MAXN];

struct Node
{
    int d;
    int v, a;
}x[MAXN];

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, l, V;
        cin >> n >> m >> l >> V;
        for (int i = 1; i <= n; i++)
            cin >> x[i].d >> x[i].v >> x[i].a;
        bool flag1 = true;
        bool flag2 = true;
        bool flag3 = true;
        for (int i = 1; i <= n; i++)
        {
            if (x[i].a != 0)
                flag1 = false;
            if (x[i].a <= 0)
                flag2 = false;
        }
        for (int i = 1; i <= m; i++)
            cin >> cs[i];

        int cnt = 0;
        if (flag1)
        {
            for (int i = 1; i <= n; i++)
            {
                if (x[i].v > V && x[i].d <= cs[m])
                    cnt ++;
            }
            cout << cnt << " ";
        }

        if (flag2)
        {
            for (int i = 1; i <= n; i++)
            {
                if (x[i].d > cs[m])
                    continue;
                double ev = sqrt(x[i].v * x[i].v * 1.0 + 2.0 * x[i].a * (cs[m] - x[i].d));
                if (ev > V)
                    cnt ++;
            }
            cout << cnt << " ";
        }

        if (cnt == 0)
        {
            cout << m << endl;
            continue;
        }
        cout << m-1 << endl;
    }
}
