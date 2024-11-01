#include <bits/stdc++.h>
using namespace std;

int a[10]{0, -1, 1, 7, 4, 2, 9};

int main()
{
    freopen ("sticks.in", "r", stdin);
    freopen ("sticks.out", "w", stdout);
    int mt;
    cin >> mt;
    for (int i = 1; i <= mt; i++)
    {
        int n;
        cin >> n;
        if (n % 7 == 1)
        {
            cout << -1;
            continue;
        }
        if (n % 7 != 0)
        {
            cout << a[n % 7];
        }
        for (int j = 1; j <= n / 7; j++)
        {
            cout << 8;
        }
        cout << endl;
    }
    return 0;
}
