#include <bits/stdc++.h>
#define int long long
using namespace std;
int num[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
signed main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 1e18;
        cin >> n;
        if (n % 7 == 0)
        {
            for (int i = 1; i <= n / 7; i++) cout << 8;
            cout << endl;
        }
        else if (n % 7 == 1 && n > 1)
        {
            cout << 10;
            for (int i = 1; i <= n / 7 - 1; i++) cout << 8;
            cout << endl;
        }
        else cout << -1;
    }
    return 0;
}
