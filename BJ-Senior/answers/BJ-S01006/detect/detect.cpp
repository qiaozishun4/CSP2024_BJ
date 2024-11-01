#include <bits/stdc++.h>
using namespace std;
int n, m, l, v, a[100010];
struct car
{
    int d, v, x;
}c[100010];
int answer()
{
    int ans1 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (c[i].x > 0)
        {
            if (c[i].d <= a[m])
            {
                if (sqrt((a[m] - c[i].d) * 2 * c[i].x + c[i].v * c[i].v) >= v)
                {
                    ans1++;
                }
            }
        }
        else if (c[i].x == 0)
        {
            if (c[i].v > v && c[i].d <= a[m])
            {
                ans1++;
            }
        }
        else
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[j] == -1) continue;
                if (a[j] >= c[i].d)
                {
                    if (sqrt((a[j] - c[i].d) * 2 * c[i].x + c[i].v * c[i].v) >= v)
                    {
                        ans1++;
                    }
                    break;
                }
            }
        }
    }
    return ans1;
}
int main ()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> l >> v;
        for (int i = 1; i <= n; i++) cin >> c[i].d >> c[i].v >> c[i].x;
        for (int i = 1; i <= m; i++) cin >> a[i];
        sort(a + 1, a + m + 1);
        int ans = answer();
        cout << ans << " ";
        bool flag = 1;
        for (int i = 1; i <= n; i++)
        {
            if (c[i].x <= 0) flag = 0;
        }
        if (flag == 1)
        {
            cout << m - 1 << endl;
            continue;
        }
        flag = 1;
        for (int i = 1; i <= n; i++)
        {
            if (c[i].x != 0) flag = 0;
        }
        if (flag == 1)
        {
            cout << m - 1 << endl;
            continue;
        }
        bool f = 0;
        int ans2 = 0;
        for (int k = m; k >= 1; k--)
        {
            int t = a[k];
            a[k] = -1;
            if (f == 0) m--;
            if (answer() == ans)
            {
                ans2++;
            }
            else
            {
                if (f == 0)
                {
                    m++;
                    f = 1;
                }
                a[k] = t;
            }
        }
        cout << ans2 << endl;
    }
    return 0;
}
