#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100010];
signed main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int ans = 0;
        for(int i = 0; i <= (1 << n); i++)
        {
            int sum = 0;
            for(int j = 1; j <= n; j++)
            {
                int op = j - 1;
                while(op > 0 && (((i >> j) & 1) != ((i >> op) & 1)))
                {
                    op--;
                }
                if(op == 0) continue;
                sum += a[j] * (a[j] == a[op]);
            }
            ans = max(ans, sum);
        }
        cout << ans << endl;
    }
    return 0;
}
