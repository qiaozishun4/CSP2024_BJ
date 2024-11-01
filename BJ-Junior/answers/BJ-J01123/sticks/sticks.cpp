#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int numArr[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void solve()
{
    cin >> n;
    if (n < 2)
        cout << -1 << endl;
    else
    {
        if (n % 7 == 0 && n >= 100)
        {
            int cnt = 0;
            while (cnt != n)
            {
                cout << 8;
                cnt += 7;
            }
        }

        cout << endl;
    }
}

signed main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();

    return 0;
}
