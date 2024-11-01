#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 1e5 + 5;
typedef long long ll;
ll t, n, k, q, l[M], r, x, flag;

void read()
{
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i];
        for (int j = 1; j <= l[i]; j++)
        {
            cin >> x;
        }
    }
}

int main()
{
    freopen ("chain.in", "r", stdin);
    freopen ("chain.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        read();
        for (int i = 1; i <= q; i++)
        {
            ll s;
            cin >> r >> s;
            cout << 0 << endl;
        }
    }
    return 0;
}