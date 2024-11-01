#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n, a[N], t;
ll d[N], ans;
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while (t--)
    {
        ans = 0;
        memset(d, 0, sizeof(d));

        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            //h[a[i]]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (a[i-1] == a[i] || a[i-2] == a[i] || a[i-3] == a[i])
            {
                d[i] += a[i];
            }
        }

        for (int i = 1; i <= n; i++) ans += d[i];

        //for (int i = 1; i <= n; i++) cout << d[i] << " ";

        cout << ans << "\n";
    }
    
    return 0;
}