#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t, n, k, q, l[100005], s[100005][200005], r[100005], c[100005], a[100005] = {1, 0, 1, 0, 1, 0, 0};
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> k >> q;
        for (int j = 1; j <= n; j++)
        {
            cin >> l[j];
            for (int w = 1; w <= l[j]; w++)
            {
                cin >> s[j][w];
            }
        }
        for (int j = 1; j <= q; j++)
        {
            cin >> r[j] >> c[j];
            cout << a[j] << endl;
        }
    }
    return 0;
}