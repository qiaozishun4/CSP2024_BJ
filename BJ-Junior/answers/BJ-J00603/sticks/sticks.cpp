#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
ll t, n;
ll ans[15] = {0, -1, 1, 7, 4, 2, 6, 8, 10, 18,  22, 20, 28, 68, 88};
int main()
{
    freopen ("sticks.in", "r", stdin);
    freopen ("sticks.out", "w", stdout);
    cin >> t;
    while (t --)
    {
        cin >> n;
        ll op = n / 7;
        if (n < 15) cout << ans[n] << endl;
        else
        {
            if (n % 7 != 0) op ++;
            op -= 3;
            ll k = n % 7;
            if (k == 1)
                cout << 108;
            if (k == 2)
                cout << 188;
            if (k == 3)
                cout << 200;
            if (k == 4)
                cout << 208;
            if (k == 5)
                cout << 288;
            if (k == 6)
                cout << 688;
            if (k == 7)
                cout << 888;
            for (int i = 1; i <= op; i++)
                cout << 8;
            cout << endl;
        }
    }
    return 0;
}