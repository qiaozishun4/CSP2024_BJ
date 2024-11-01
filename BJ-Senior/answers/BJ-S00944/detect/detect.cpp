#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int d[100005], v[100005], a[100005], p[100005];
void sol()
{
    int n, m, l, k;
    cin >> n >> m >> l >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i] >> v[i] >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> p[i];
    }
    sort(p + 1, p + m + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] > k && d[i] <= p[m])
        {
            cnt++;
        }
    }
    cout << cnt << " " << (cnt ? m - 1 : m) << endl;
}
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    for (cin >> t; t; t--)
    {
        sol();
    }
    return 0;
}
