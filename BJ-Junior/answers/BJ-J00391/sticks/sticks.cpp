#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t, n, a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        if (n <= 7)
        {
            if (n == 1)
            {
                cout << -1;
            }
            for (int i = 0; i < 10; i++)
            {
                if (n == a[i])
                {
                    cout << i << endl;
                }
            }
        }
        else if (n % 7 == 0)
        {
            for (int i = 1; i <= n / 7; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if (n % 7 == 1)
        {
            cout << 10;
            for (int i = 1; i <= (n - 8) / 7; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if (n % 7 == 2)
        {
            cout << 1;
            for (int i = 1; i <= n / 7; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if (n % 7 == 3)
        {
            cout << 7;
            for (int i = 1; i <= n / 7; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if (n % 7 == 4)
        {
            cout << 4;
            for (int i = 1; i <= n / 7; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if (n % 7 == 5)
        {
            cout << 2;
            for (int i = 1; i <= n / 7; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if (n % 7 == 6)
        {
            cout << 80;
            for (int i = 1; i <= n / 7 - 1; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
    }
    return 0;
}